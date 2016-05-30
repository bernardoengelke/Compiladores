#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

void Block::printTree(){
    for (Node* line: lines) {
        line->printTree();
        std::cout << std::endl;
    }
}
