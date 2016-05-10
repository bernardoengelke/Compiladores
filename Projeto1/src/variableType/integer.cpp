#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

void Integer::printTree(){
  std::cout<<value;
}

int Integer::computeTree(){
  return value;
}
