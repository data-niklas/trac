%{
#include <string>

/* Implementation of yyFlexScanner */ 
#include "./TracScanner.h"
#undef  YY_DECL
#define YY_DECL int parser::TracScanner::yylex( \
  parser::TracParser::semantic_type * const lval, \
  parser::TracParser::location_type * loc)

/* typedef to make the returns for the tokens shorter */
using token = parser::TracParser::token;

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option nodefault
%option yyclass="parser::TracScanner"
%option noyywrap
%option c++
%option prefix="yyTrac"

%x MULTI_LINE_COMMENT
%x SINGLE_LINE_COMMENT

WS [ \t\b\f\r]+

%%
%{          
/* Executed at the beginning of yylex */
yylval = lval;
%}


{WS} { ; }


"//" { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT>.    { yymore(); }
<SINGLE_LINE_COMMENT>\n   { loc->lines(); BEGIN(0); }

"/*" { BEGIN(MULTI_LINE_COMMENT); }
<MULTI_LINE_COMMENT>.    { yymore(); }
<MULTI_LINE_COMMENT>\n   { loc->lines(); yymore(); }
<MULTI_LINE_COMMENT>"*/" { BEGIN(0); }

\n { loc->lines(); }

"(" { return token::LPAREN;}
")" { return token::RPAREN;}
":" { return token::COLON;}
"?" { return token::QUESTION;}
"!" { return token::ACTION;}
";" { return token::SEMICOLON;}
"_" { return token::VOID;}

 /* Keywords */
	
 /* Floating Point: +1e10, 1e5, -1e-3 */
[+-]?[0-9]+([Ee][+-]?[0-9]+) {
	yylval->build<double>(std::stod(std::string(yytext)));
	return token::FLOAT;
}

 /* Floating Point: +1.02e10, 1.003, -1e-3, .0 */
[+-]?[0-9]*\.[0-9]+([Ee][+-]?[0-9]+)? {
	yylval->build<double>(std::stod(std::string(yytext)));
	return token::FLOAT;
}

 /* Integer */
 
[+-]?[0-9][0-9]* {
		yylval->build<long>(std::stol(std::string(yytext)));
		return token::INTEGER;
}
 
true {
		yylval->build<bool>(true);
		return token::BOOL;
}
 
false {
		yylval->build<bool>(false);
		return token::BOOL;
}

 /* String */
 
\"([^"\n]|\\n)*["] {
		// Note: '\r' is handled as a whitespace, so we don't need to deal 
		// with it here.
		yytext[yyleng-1] = '\0';
		std::string text = std::string(yytext + 1);
		long unsigned int pos;
		while((pos = text.find("\\n")) != std::string::npos) {
        	text.replace(pos, 2, "\n");
    	}
		yylval->build<std::string>(text); // +1 skips initial quote	
		return token::STRING;		
}

[^\t\b\f\r\n/ ():!?;"]+ {
		yylval->build<std::string>(yytext);
		return token::IDENTIFIER; 
}
 
 /* Unmatched */

. { return yytext[0]; }

 /* ------------------------------------------------------------------------- */

%%

	
