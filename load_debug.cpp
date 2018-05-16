/*
 * load_debug.cpp
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


void load_debug () 
{
	struct list_entry *current;
	int i;
	int j=0;
	int k=0;
	int iflagset;
	char *isset[] = { "not set", "set" };

	if ( options.debug_level > 0 ) fprintf(stderr,"   debug verbosity = %i\n",options.debug_level);
	if ( options.debug_level > 0 ) debugInitialVirbosity = debugVirbosity = options.debug_level;

	bdebug_flag_set[0] = bdebug_flag_set[NUMDEBUGFLAGS-1] = 0;

	if ( (current = options.debug_flags->head) )
	{
		do {
			k++;
			for(i=0;i<NUMDEBUGFLAGS;i++) {
				if( strcmp(debug_flag[i], current->data) == 0 ) {
					bdebug_flag_set[i] = 1;
					j++;
				}
			}
			if ( j != k ) fprintf(stderr, " %s is not a valid debug flag\n", current->data);
		} while ((current = current->next));
	}
	if ( j != k ) {
		fprintf(stderr," see --list=debug-flags\n");
		exit(EXIT_FAILURE);
	}
	if ( bdebug_flag_set[ALLON] ) {
		for(i=0;i<NUMDEBUGFLAGS;i++){
			if ( i != QUIET && i != NONE ) bdebug_flag_set[i]=1;
		}
	} 
	if ( (current = options.debug_flags->head) ) {
		fprintf(stderr,"   debug flags set : ");
		do {
			fprintf(stderr, "%s", current->data);
			if ( current->next ) fprintf(stderr, ",");
		} while ( ( current = current->next ) );
		fprintf(stderr,"\n");
	}

	iDebugOutputDevice = -1;

	if ( options.debug_server_name != NULL ) lpDebugServerName = options.debug_server_name;
	if ( options.degug_port_number != 0 ) port = options.degug_port_number;
	if ( options.debug_filename != NULL ) lpDebugOutputFileName = options.debug_filename;
	if ( options.debug_device != NULL ) {
		for(i = 0;i < DIMDEBUGDEVICES;i++) {
			if ( strcmp (OuputDeviceType[i] , options.debug_device) == 0 ) iDebugOutputDevice = i;
		}
		if ( iDebugOutputDevice == -1 ) {
			iDebugOutputDevice = BITBUCKET;
			fprintf(stderr," %s is not a valid debug output device, see --list=debug-device\n", options.debug_device);
			exit(EXIT_FAILURE);
		}
	}
	if ( options.debug_color_flag != 0 ) { ColorDebug = 1; }
		else ColorDebug = 0;
	if ( options.debug_clear_screen > 0 && options.debug_clear_screen < 4) { ClearDebugScreenOnExit = options.debug_clear_screen; }
		else ClearDebugScreenOnExit = 0;
	if ((current = options.debug_mask_messages->head)) {
		printf("messages to mask:\n");
		do {
			printf("   %s\n",current->data);
		} while ((current = current->next));
	}
	if ((current = options.debug_display_messages->head)) {
		printf("messages to display:\n");
		do {
			printf("   %s\n",current->data);
		} while ((current = current->next));
	}

//	iDebugOutputDevice = iDebugOutputDeviceSave;
//	if (debugflag > 0) {
		if ( OpenDebugDevice() == 0 ) {
			fprintf(stderr,"OpenDebugDevice failed\n");
		} else {
			dfprintf(__LINE__,__FILE__,DEBUGINIT,"\33[1;32mDebug output device set to type %i\33[0m (%s)\n", iDebugOutputDevice,OuputDeviceType[iDebugOutputDevice]);
			iflagset = 0;
#ifdef JUMBO_JTR
			iflagset = 1;
#endif
			dfprintf(__LINE__,__FILE__,DEBUGINIT,"\33[1;32m JUMBO_JTR is %s\33[0m\n", isset[iflagset]);
			iflagset = 0;
#ifdef BENCH_BUILD
			iflagset = 1;
#endif
			dfprintf(__LINE__,__FILE__,DEBUGINIT,"\33[1;32m BENCH_BUILD is %s\33[0m\n", isset[iflagset]);
			iflagset = 0;
#ifdef _MSC_VER
			iflagset = 1;
#endif
			dfprintf(__LINE__,__FILE__,DEBUGINIT,"\33[1;32m _MSC_VER is %s\33[0m\n", isset[iflagset]);
			iflagset = 0;
#ifdef ARCH_ALLOWS_UNALIGNED
			iflagset = 1;
#endif
			dfprintf(__LINE__,__FILE__,DEBUGINIT,"\33[1;32m ARCH_ALLOWS_UNALIGNED is %s\33[0m\n", isset[iflagset]);
			iflagset = 0;
#ifdef HAVE_OPENCL
			iflagset = 1;
#endif
			dfprintf(__LINE__,__FILE__,DEBUGINIT,"\33[1;32m HAVE_OPENCL is %s\33[0m\n", isset[iflagset]);
			iflagset = 0;
#ifdef HAVE_CUDA
			iflagset = 1;
#endif
			dfprintf(__LINE__,__FILE__,DEBUGINIT,"\33[1;32m HAVE_CUDA is %s\33[0m\n", isset[iflagset]);
			iflagset = 0;
#ifdef DYNA_SALT_DEBUG
			iflagset = 1;
#endif
			dfprintf(__LINE__,__FILE__,DEBUGINIT,"\33[1;32m DYNA_SALT_DEBUG is %s\33[0m\n", isset[iflagset]);
		}
		if ( bdebug_flag_set[QUIET] ) debugVirbosity = 0;

//	}
	return;
}
