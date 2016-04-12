%{
#include "ast.h"
#include "st.h"
AST::Block *programRoot; /* the root node of our program AST:: */
ST::SymbolTable symtab; /* main symbol table */
extern int yylex();
extern void yyerror(const char* s, ...);
%}

/* yylval == %union
 * union informs the different ways we can store data
 */

%union {
    int integer;
    const char * string;

    AST::Node *node;
    AST::Block *block;
}

/* token defines our terminal symbols (tokens).
 */
%token <integer> T_INT
%token <string> T_VAR
%token T_PLUS T_NL T_MULT
%token T_DEF T_SEPARATOR T_ASSIGN

/* type defines the type of our nonterminal symbols.
 * Types should match the names used in the union.
 * Example: %type<node> expr
 */
%type <node> expr line variaveis
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
        | T_DEF variaveis T_NL {$$ = $2; std::cout << "Definitions founded" << std::endl;}
        | T_VAR T_ASSIGN expr { AST::Node* node = symtab.assignVariable($1);
                                $$ = new AST::BinOp(node,AST::assign, $3);}
        ;

variaveis      : T_VAR { $$ = symtab.newVariable($1, NULL); std::cout << "Vairable definition founded" << std::endl;}
               | variaveis T_SEPARATOR T_VAR { $$ = symtab.newVariable($3, $1); std::cout << "Vairable definition founded" << std::endl;}
               ;

expr    : T_INT { $$ = new AST::Integer($1); std::cout << "Integer founded" << std::endl; }
        | T_VAR { $$ = symtab.useVariable($1); std::cout << "Variable founded" << std::endl; }
        | expr T_PLUS expr { $$ = new AST::BinOp($1,AST::plus,$3); std::cout << "Plus operation founded" << std::endl; }
        | expr T_MULT expr { $$ = new AST::BinOp($1,AST::mult,$3); std::cout << "Multiply operation founded" << std::endl; }
        | expr error { yyerrok; $$ = $1; } /*just a point for error recovery*/
        ;

%%
