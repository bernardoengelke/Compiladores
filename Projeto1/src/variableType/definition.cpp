#include "variables.h"

using namespace VAR;

void Definition::printTree(){
  std::cout << "Declaração de ";
  root->printTree();
  return;
}
