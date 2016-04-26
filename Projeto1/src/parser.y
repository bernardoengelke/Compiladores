%{
#include "ast.h"
#include "st.h"
AST::Block *programRoot; /* the root node of our program AST:: */
ST::SymbolTable symtab; /* main symbol table */
extern int yylex();
extern void yyerror(const char* s, ...);
%}

%define parse.trace
/* yylval == %union
 * union informs the different ways we can store data
 */

%union {
    const char * string;
    int integer;
    float real;
    bool boolean;
}

/* token defines our terminal symbols (tokens).
 */
%token D_INT D_REAL D_BOOL

%token <string> T_VAR
%token <integer> T_INT
%token <real> T_REAL

%token <boolean> T_TRUE T_FALSE

%token T_PLUS T_SUB T_MULT T_DIV
%token T_COMMA T_SEPARATOR T_ASSIGN T_EOFL

%token T_EQUALS T_NEQUALS
%token T_BIGGEST T_SMALLEST T_BIGOREQUALS T_SMALLOREQUALS

%token T_AND T_OR T_NOT
%token T_OPENP T_CLOSEP

%token T_NL
/* type defines the type of our nonterminal symbols.
 * Types should match the names used in the union.
 * Example: %type<node> expr
 */
%type <node> expr line variaveis
%type <block> lines program

/* Operator precedence for mathematical operators
 * The latest it is listed, the highest the precedence
 */
%left T_PLUS T_SUB
%left T_MULT T_DIV
%nonassoc error

/* Starting rule
 */
%start program

%%

program : lines { programRoot = $1; std::cout << "End of entries" << std::endl;}
        ;


lines   : line { $$ = new AST::Block(); $$->lines.push_back($1); std::cout << "New line was founded" << std::endl;}
        | lines line { if($2 != NULL) $1->lines.push_back($2); }
        ;

line    : T_NL { $$ = NULL; std::cout << "Nothing to be used" << std::endl;} /*nothing here to be used */
        | expr T_NL /*$$ = $1 when nothing is said*/
        ;

expr    : T_INT { $$ = new AST::Integer($1); std::cout << "Integer founded" << std::endl; }
        | T_VAR { $$ = symtab.useVariable($1); std::cout << "Variable founded" << std::endl; }
        | expr T_PLUS expr { $$ = new AST::BinOp($1,AST::plus,$3); std::cout << "Plus operation founded" << std::endl; }
        | expr T_MULT expr { $$ = new AST::BinOp($1,AST::mult,$3); std::cout << "Multiply operation founded" << std::endl; }
        | expr error { yyerrok; $$ = $1; } /*just a point for error recovery*/
        ;

%%
