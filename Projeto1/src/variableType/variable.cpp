#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

extern ST::SymbolTable symtab;

int Variable::computeTree(){
  return symtab.entryList[name].value;
}

void Variable::printTree(){
    std::cout << name;
    return;
}
