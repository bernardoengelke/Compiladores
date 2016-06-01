#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

void Bool::printTree(){
  std::cout << "valor booleano ";
  std::cout << (value?"TRUE":"FALSE");
}

void Bool::printType(Genre genre){
  std::string output = genre == Genre::MASC ? "booleano" : "booleana";
  std::cout << output;
}
