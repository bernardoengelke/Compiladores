%{
#include "variableType/variables.h"
#include "symbolTable/symbolTable.h"
VAR::Block *programRoot; /* the root node of our program VAR:: */
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

    VAR::Node *node;
    VAR::Block *block;
}

/* token defines our terminal symbols (tokens).
 */
%token <string>D_INT D_REAL D_BOOL

%token <string> T_VAR
%token <integer> T_INT
%token <real> T_REAL

%token <boolean> T_TRUE T_FALSE

%token T_PLUS T_SUB T_MULT T_DIV
%token T_COMMA T_ASSIGN_TYPE T_ASSIGN T_EOFL

%token T_EQUALS T_NEQUALS
%token T_BIGGEST T_SMALLEST T_BIGOREQUALS T_SMALLOREQUALS

%token T_AND T_OR T_NOT
%token T_OPENP T_CLOSEP


%type <node> expr line variables
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
program : lines { programRoot = $1; std::cout << "End of entries" << std::endl; }
        ;


lines   : line { $$ = new VAR::Block(); $$->lines.push_back($1); }
        | lines line { if($2 != NULL) $1->lines.push_back($2); }
        ;


line    : T_EOFL { $$ = NULL; }/*nothing here to be used */
        | expr T_EOFL /*$$ = $1 when nothing is said*/
        | D_INT T_ASSIGN_TYPE variables T_EOFL {$$ = symtab.updateTypeVariable(ST::D_INTEGER, $3); std::cout << "Definitions founded" << std::endl;}
        | T_VAR T_ASSIGN expr { VAR::Node* node = symtab.assignVariable($1); $$ = new VAR::BinOp(node,VAR::T_ASSIGN, $3);}
        ;


variables : T_VAR { $$ = symtab.newVariable($1, NULL); std::cout << "Vairable definition founded" << std::endl;}
          | variables T_COMMA T_VAR { $$ = symtab.newVariable($3, $1); std::cout << "Vairable definition founded" << std::endl;}
          ;

expr    : T_INT { $$ = new VAR::Integer($1); }
        | T_VAR { $$ = symtab.useVariable($1); std::cout << "Variable founded" << std::endl; }
        | expr T_PLUS expr { $$ = new VAR::BinOp($1, VAR::T_PLUS, $3); }
        | expr T_SUB expr { $$ = new VAR::BinOp($1, VAR::T_SUB, $3); }
        | expr T_MULT expr { $$ = new VAR::BinOp($1, VAR::T_MULT, $3); }
        | expr T_DIV expr { $$ = new VAR::BinOp($1, VAR::T_DIV, $3); }
        | expr error { yyerrok; $$ = $1; } /*just a point for error recovery*/
        ;

%%
