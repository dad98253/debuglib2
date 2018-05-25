/*
 * debug_read_proc_file.cpp
 *
 *  Created on: May 16, 2018
 *      Author: dad
 */

#ifdef WINDOZE
#pragma message( "Compiling " __FILE__ " on " __DATE__ " at " __TIME__ )
#pragma message( "File last modified on " __TIMESTAMP__ )
#pragma message( "  ")
#pragma title( "debuglib version 2.0" )
#pragma subtitle( "Copyright (c) 2018, Nehemiah Ministries, Inc." )
#pragma comment( compiler )
#pragma comment( user, "File: " __FILE__ ". Compiled on " __DATE__ " at " __TIME__ ".  Last modified on " __TIMESTAMP__ )
#endif


#include "debug.h"
#include "debug01.h"
#include <stdlib.h>
#include <string.h>



int debug_read_proc_file(int idumpem) 
{
#define MAXPFNAMELEN	100
	char pfname[MAXPFNAMELEN];
	char maploc[MAXPFNAMELEN];
	char mode[MAXPFNAMELEN];
	char *line = NULL;
	FILE *procfile;
	ssize_t linelen;
	size_t maxlen = 0;
	int numread,pfnlen;
	unsigned int startoffset,devmaj,devmin,inode;
	unsigned long long int startadd,endadd;
	
	mypid = getpid();
	myppid = getppid();
	pfnlen = snprintf(pfname,MAXPFNAMELEN,"/proc/%u/maps",(unsigned int)mypid);
	if (pfnlen > (MAXPFNAMELEN - 2) ) {
		fprintf(stderr,"unable to construct proc file name : %s\n",pfname);
		exit(EXIT_FAILURE);
	}
	if ((procfile = fopen(pfname, "r")) == NULL) {
		fprintf(stderr,"unable to open %s file.\n",pfname);
		exit(EXIT_FAILURE);
	}
	while ( (linelen = getline(&line, &maxlen, procfile)) > 0 ) {
		numread=strlen(line);
		if(numread>0) line[numread-1]='\000';
		if ( idumpem ) dfprintf(__LINE__,__FILE__,NOHEADspecial," %s\n", line);
		numread = sscanf ( line, "%llx-%llx %s %x %x:%x %u %s", &startadd,&endadd,mode,&startoffset,&devmaj,&devmin,&inode,maploc);
		if ( numread != 7 && numread != 8 ) {
			fprintf(stderr,"unable to parse line in /proc/../maps file : %s \n",line);
			fclose(procfile);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = NULL;
		if (strcmp(maploc,"[heap]") == 0 ) {
			debugheapstart = startadd;
			debugheapend = endadd;			
		}
		if (strcmp(maploc,"[stack]") == 0 ) {
			debugstackstart = startadd;
			debugstackend = endadd;			
		}
	}
	fclose(procfile);

	return 0;
}

