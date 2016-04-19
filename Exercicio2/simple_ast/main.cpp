#include <iostream>
#include "ast.h"

extern AST::Block* programRoot; //set on Bison file
extern int yyparse();
extern int yydebug;

int main(int argc, char **argv)
{
    yydebug = 1;
    yyparse();                  //parses whole data
    programRoot->printTree();   //prints the ASTs
    programRoot->computeTree(); //computes the ASTs
    return 0;
}
