#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

void Bool::printTree(){
  std::cout << "valor booleano ";
  std::cout << (value?"TRUE":"FALSE");
}
