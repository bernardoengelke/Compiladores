#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

void Integer::printTree(){
  std::cout << "valor inteiro ";
  std::cout << value;
}

void Integer::printType(Genre genre){
  std::string output = genre == Genre::MASC ? "inteiro" : "inteira";
  std::cout << output;
}
