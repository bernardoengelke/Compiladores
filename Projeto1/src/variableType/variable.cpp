#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

extern ST::SymbolTable symtab;

void Variable::printTree(){

    std::cout << name;
    if(next){
      Variable* node = dynamic_cast<Variable*>(next);
      std::cout << ",";
      node->printTree();
    }
    return;
}
