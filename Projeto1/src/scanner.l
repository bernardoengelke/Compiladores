%{
#include <string>
#include "variableType/variables.h"
#include "parser.h"
#include "string.h"
extern int yylineno;
void yyerror(const char* s, ...);
%}

%option noyywrap nodefault yylineno

_digs [0-9]+
_var  [a-z]+

_int {_digs}
_real "."{_digs}|{_digs}"."|{_digs}"."{_digs}

%%

[ \t \n]               ; //ignores spaces
 /*definições*/
"int"               {return D_INT;}
"real"              {return D_REAL;}
"bool"              {return D_BOOL;}

 /*valores*/
{_var}              {yylval.string = strdup(yytext); return T_VAR;}
{_int}              {yylval.integer = std::atoi(yytext); return T_INT;}
{_real}             {yylval.real = std::atof(yytext); return T_REAL;}

 /*valores booleanos*/
"TRUE"              {yylval.boolean = true; return T_TRUE;}
"FALSE"             {yylval.boolean = false; return T_FALSE;}

 /*operadores aritmétricos*/
"+"                 {return T_PLUS;}
"-"                 {return T_SUB;}
"*"                 {return T_MULT;}
"/"                 {return T_DIV;}

 /*Separador e atribuiçã*/
","                 {return T_COMMA;}
":"                 {return T_ASSIGN_TYPE;}
":="                {return T_ASSIGN;}
";"                 {return T_EOFL;}

 /*operadores relacionais*/
"="                 {return T_EQUALS;}
"~="                {return T_NEQUALS;}
">"                 {return T_BIGGEST;}
"<"                 {return T_SMALLEST;}
">="                {return T_BIGOREQUALS;}
"<="                {return T_SMALLOREQUALS;}

 /*operadores binários*/
"AND"               {return T_AND;}
"OR"                {return T_OR;}
"~"                 {return T_NOT;}

 /*parenteses*/
"("                 {return T_OPENP;}
")"                 {return T_CLOSEP;}

.                   {yyerror("Unknown token! %c\n", *yytext);} /*complains about every unknown character*/

%%

void yyerror(const char *s, ...){
    va_list ap;
    va_start(ap, s);
    std::fprintf(stderr, "Line %d: error: ", yylineno);
    std::vfprintf(stderr, s, ap);
}
