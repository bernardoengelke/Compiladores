%{
#include "ast.h"
AST::Block *programRoot; /* the root node of our program AST:: */
extern int yylex();
extern void yyerror(const char* s, ...);
%}

/* yylval == %union
 * union informs the different ways we can store data
 */

%union {
    int integer;
    char * string;

    AST::Node *node;
    AST::Block *block;
}

/* token defines our terminal symbols (tokens).
 */
%token <integer> T_INT
%token <string> T_VAR
%token T_PLUS T_NL T_MULT
%token T_DEF

/* type defines the type of our nonterminal symbols.
 * Types should match the names used in the union.
 * Example: %type<node> expr
 */
%type <node> expr line
%type <block> lines program

/* Operator precedence for mathematical operators
 * The latest it is listed, the highest the precedence
 */
%left T_PLUS
%left T_MULT
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
        | T_DEF T_VAR T_NL { $$ = new AST::Variavel($2); std::cout << "Vairable definition founded" << std::endl;}
        ;

expr    : T_INT { $$ = new AST::Integer($1); std::cout << "Integer founded" << std::endl; }
        | T_VAR { $$ = new AST::Variavel($1); std::cout << "Variable founded" << std::endl; }
        | expr T_PLUS expr { $$ = new AST::BinOp($1,AST::plus,$3); std::cout << "Plus operation founded" << std::endl; }
        | expr T_MULT expr { $$ = new AST::BinOp($1,AST::mult,$3); std::cout << "Multiply operation founded" << std::endl; }
        | expr error { yyerrok; $$ = $1; } /*just a point for error recovery*/
        ;

%%
