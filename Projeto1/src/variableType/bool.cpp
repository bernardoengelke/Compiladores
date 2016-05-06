#include "variables.h"

using namespace VAR;

void Bool::printTree(){
  std::cout<<value;
}

int Bool::computeTree(){
  return value;
}
