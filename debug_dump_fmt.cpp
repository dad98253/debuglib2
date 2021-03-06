/*
 * debug_dump_fmt.cpp
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

void debug_dump_fmt( void *x, unsigned int size)
{
#ifdef DEBUG
	unsigned int i;

	if ( debugpointertest(x) ) {
		for(i=0;i<size;i++)
		{
//dfprintf2(__LINE__,__FILE__,TRACE,"i = %i, NOHEADspecial = %i, print char at %p:\n",i , NOHEADspecial, ((unsigned char*)x)[i]);
			dfprintf2(__LINE__,__FILE__,NOHEADspecial,"%02x", ((unsigned char*)x)[i]);
			if( (i%4)==3 ) {
				dfprintf2(__LINE__,__FILE__,NOHEADspecial," ");
			}
		}
		dfprintf2(__LINE__,__FILE__,NOHEADspecial," ___ ");
		for(i=0;i<size;i++)
		{
			if ( isprint(((unsigned char*)x)[i]) ) {
				dfprintf2(__LINE__,__FILE__,NOHEADspecial,"%c", ((unsigned char*)x)[i]);
			} else {
				dfprintf2(__LINE__,__FILE__,NOHEADspecial,".");
			}
			if( (i%4)==3 ) {
				dfprintf2(__LINE__,__FILE__,NOHEADspecial," ");
			}
		}
	} else {
		dfprintf2(__LINE__,__FILE__,TRACE,"debug_dump_fmt: bad call, argument pointer is %s\n", debugpointer2str(x));
	}
#endif	// DEBUG
	return;
}
