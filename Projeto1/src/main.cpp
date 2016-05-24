#include <iostream>
#include "variableType/variables.h"

extern VAR::Block* programRoot; //set on Bison file
extern FILE* yyin;
extern int yyparse();
extern int yydebug;

int main(int argc, char **argv)
{
    yydebug = 0;
    yyparse();
    programRoot->printTree();
    programRoot->computeTree();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Erro durante o parsing: %s\n", s);
    exit(1);
}
