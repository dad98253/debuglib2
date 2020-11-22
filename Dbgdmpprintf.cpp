/*
 * Dbgdmpprintf.cpp
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


int Dbgdmpprintf( const char * fmt,...)
{
va_list args;

int nTmp = 0;

    va_start(args, fmt);
#ifdef DEBUG
    nTmp = Dbgprintf(0,"", NOHEADspecial, fmt, args);
#endif  // DEBUG
    va_end(args);
    return(nTmp);
}
