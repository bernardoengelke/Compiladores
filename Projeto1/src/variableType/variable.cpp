#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

extern ST::SymbolTable symtab;

void Variable::printTree(){
  if(!next){
    std::cout << "variável ";

    switch (symtab.entryList[name].type){
      case ST::D_INTEGER:
        std::cout << "inteira: ";
        break;
      case ST::D_REAL:
        std::cout << "real: ";
        break;
      case ST::D_BOOLEAN:
        std::cout << "booleana: ";
        break;
      default:
        std::cout << "desconhecida: ";
        break;
    }
  }else{
    Variable* node = dynamic_cast<Variable*>(next);
    node->printTree();
    std::cout << ", ";
  }
  std::cout << name;
  return;
}
