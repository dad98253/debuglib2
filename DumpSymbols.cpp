/*
 * DumpSymbols.cpp
 *
 *  Created on: May 2, 2018
 *      Author: dad
 */
#ifdef WINDOZE
#pragma message( "Compiling " __FILE__ " on " __DATE__ " at " __TIME__ )
#pragma message( "File last modified on " __TIMESTAMP__ )
#pragma message( "  ")
#pragma comment( compiler )
#pragma comment( user, "File: " __FILE__ ". Compiled on " __DATE__ " at " __TIME__ ".  Last modified on " __TIMESTAMP__ )
#endif

//#define DEBUG
#include <stdio.h>
//#include "lindows.h"
//#include "passwin.h"
//#include "getopt.h"
//#include "options.h"
//#include "debugflags.h"
//#include "globals.h"
#include "debug.h"

void DumpSymbols(char * where) {

	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"DumpSymbols called from %s\n",where);

	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m DEBUG\33[0m set\n");

#ifdef WINDOZE
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m WINDOZE\33[0m set\n");
#else
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m WINDOZE\33[0m not set\n");
#endif

#ifdef GENRESFILE
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m GENRESFILE\33[0m set\n");
#else
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m GENRESFILE\33[0m not set\n");
#endif

#ifdef TEXTMODEONLY
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m TEXTMODEONLY\33[0m set\n");
#else
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m TEXTMODEONLY\33[0m not set\n");
#endif

#ifdef DEBUGWCSTOMBS
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m DEBUGWCSTOMBS\33[0m set\n");
#else
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m DEBUGWCSTOMBS\33[0m not set\n");
#endif

#ifdef TESTTUTX2
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m TESTTUTX2\33[0m set\n");
#else
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m TESTTUTX2\33[0m not set\n");
#endif

#ifdef GENMEMFILE
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m GENMEMFILE\33[0m set\n");
#else
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m GENMEMFILE\33[0m not set\n");
#endif

#ifdef DOMYTUTIO
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m DOMYTUTIO\33[0m set\n");
#else
	dfprintf2(__LINE__,__FILE__,NOHEADspecial,"\33[1;31m DOMYTUTIO\33[0m not set\n");
#endif

	return;
}




