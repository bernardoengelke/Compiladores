%{
#include <string>
#include "ast.h"
#include "parser.h"
#include "string.h"
extern int yylineno;
void yyerror(const char* s, ...);
%}

%option noyywrap nodefault yylineno

_digs [0-9]+
_var  [a-z]+

%%

[ \t]               ; //ignores spaces
"def"               {return T_DEF;}
{_var}              {yylval.string = yytext; return T_VAR;}
{_digs}             {yylval.integer = std::atoi(yytext); return T_INT;}
"+"                 {return T_PLUS;}
"*"                 {return T_MULT;}
\n                  {return T_NL;}
.                   {yyerror("Unknown token! %c\n", *yytext);} /*complains about every unknown character*/

%%

void yyerror(const char *s, ...){
    va_list ap;
    va_start(ap, s);
    std::fprintf(stderr, "Line %d: error: ", yylineno);
    std::vfprintf(stderr, s, ap);
}
