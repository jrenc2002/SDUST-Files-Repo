/************************************************************
yywsdop.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#include <cctype>
#else
#include <string.h>
#include <ctype.h>
#endif

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
void YYCDECL yywdebugoutput(yywint_t ch)
#else
void YYCDECL yywdebugoutput(ch)
yywint_t ch;
#endif
{
	wchar_t string[32];
	switch (ch) {
	case EOF:
		wcscpy(string, L"EOF");
		break;
	case L'\n':
		wcscpy(string, L"\\n");
		break;
	case L'\t':
		wcscpy(string, L"\\t");
		break;
	case L'\v':
		wcscpy(string, L"\\v");
		break;
	case L'\b':
		wcscpy(string, L"\\b");
		break;
	case L'\r':
		wcscpy(string, L"\\r");
		break;
	case L'\f':
		wcscpy(string, L"\\f");
		break;
	case L'\a':
		wcscpy(string, L"\\a");
		break;
	case L'\\':
		wcscpy(string, L"\\");
		break;
	case L'\?':
		wcscpy(string, L"\\\?");
		break;
	case L'\'':
		wcscpy(string, L"\\\'");
		break;
	case L'\"':
		wcscpy(string, L"\\\"");
		break;
	default:
		if (!iswascii(ch) || iswascii(ch) && iswprint((wchar_t) ch)) {
			string[0] = (wchar_t) ch;
			string[1] = L'\0';
		}
		else {
			swprintf(string, L"\\%03o", (unsigned int) ch);
		}
		break;
	}
	yywlexerdebugoutput(string);
}

#endif

_YL_END

#endif
