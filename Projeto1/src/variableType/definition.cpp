#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

extern ST::SymbolTable symtab;

void Definition::printTree(){
  std::cout << "Declaração de ";
  
  Variable::printTypeVariable(root, Genre::FEM);
  std::cout << ": ";

  Variable* node = dynamic_cast<Variable*>(root);
  printListNameOfVariable(node);

  return;
}

void Definition::printListNameOfVariable(Variable* varNode){
  if(varNode->next){
    Variable* node = dynamic_cast<Variable*>(varNode->next);
    printListNameOfVariable(node);
    std::cout << ", ";
  }
  std::cout << varNode->name;
  return;
}
