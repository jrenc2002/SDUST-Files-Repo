/************************************************************
yywclcre.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yybool yywlexer::yycreate(yywparser YYFAR* parserptr)
{
	yyparserptr = parserptr;

	// get sizes first
	int textsize = yystext_size + 1;	// include the '\0' (also allows room for yyleng)
	if (textsize <= yystext_size) {
		return yyfalse;		// integer overflow
	}

	// allocate the memory if necessary
	wchar_t YYFAR* stext = new YYFAR wchar_t[textsize];
	if (stext == NULL) {
		return yyfalse;
	}
	int YYFAR* sstatebuf;
	if (yystext_size != 0) {
		sstatebuf = new YYFAR int[yystext_size];
		if (sstatebuf == NULL) {
			delete[] stext;
			return yyfalse;
		}
	}
	else {
		sstatebuf = NULL;
	}
	yywint_t YYFAR* sunputbufptr;
	if (yysunput_size != 0) {
		sunputbufptr = new YYFAR yywint_t[yysunput_size];
		if (sunputbufptr == NULL) {
			delete[] stext;
			delete[] sstatebuf;
			return yyfalse;
		}
	}
	else {
		sunputbufptr = NULL;
	}

	yystext = stext;
	yysstatebuf = sstatebuf;
	yysunputbufptr = sunputbufptr;

	// assign any other variables
	yytext_size = yystext_size;
	yytext = yystext;
	yystatebuf = yysstatebuf;
	yyunput_size = yysunput_size;
	yyunputbufptr = yysunputbufptr;

	// makes sure we are ready to go
	yyreset();

	return yytrue;
}

_YL_END

#endif
