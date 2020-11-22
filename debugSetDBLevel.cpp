/*
 * debugSetDBLevel.cpp
 *
 *  Created on: May 16, 2018
 *      Author: dad
 */

#ifdef WINDOZE
#pragma message( "Compiling " __FILE__ " on " __DATE__ " at " __TIME__ )
#pragma message( "File last modified on " __TIMESTAMP__ )
#pragma message( "  ")
#pragma comment( compiler )
#pragma comment( user, "File: " __FILE__ ". Compiled on " __DATE__ " at " __TIME__ ".  Last modified on " __TIMESTAMP__ )
#endif


#include "debug.h"
#include "debug01.h"


unsigned char debugSetDBLevel( int DesiredLevel )
{
	unsigned char OldLevel = 0;
#ifdef DEBUG
	OldLevel = debugVirbosity;
	if ( DesiredLevel < 0 ) {
		debugVirbosity = debugInitialVirbosity;
	} else {
		debugVirbosity = (unsigned char)DesiredLevel;
	}
#endif	// DEBUG
	return(OldLevel);
}

