#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

void Real::printTree(){
  std::cout << "valor real ";
  std::cout << value;
}

void Real::printType(Genre genre){
  std::cout << "real";
}
