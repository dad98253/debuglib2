/*
 * IPSend.cpp
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


int IPSend(char * Buffer, int MaxDataSize) {
	int retval = 0;
#define IPSENDBADLIMIT	100
	static int ibadcalls = 0;

		retval = send(conn_socket,Buffer,strlen(Buffer)+1,0);
		if (retval == SOCKET_ERROR) {
#ifdef WINDOZE
			fprintf(stderr,"send() failed: error %d\n",WSAGetLastError());
			WSACleanup();
#else
		int errsv = errno;
		if ( bMyWay ) {
			fprintf(stderr,"send() failed: error %d, msg = %s\n",errsv,Buffer);
			ibadcalls++;
			if ( ibadcalls > IPSENDBADLIMIT ) bMyWay = FALSE;
		}
		else fprintf(stderr,"send() failed: error %d\n",errsv);
#endif
			return -1;
		}

//		fprintf(stderr,"Sent Data [%s]\n",Buffer);
	return 0;
}
