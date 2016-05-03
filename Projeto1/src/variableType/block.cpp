#include "variables.h"

using namespace VAR;

void Block::printTree(){
    for (Node* line: lines) {
        line->printTree();
        std::cout << std::endl;
    }
}

int Block::computeTree(){
    int value;
    for (Node* line: lines) {
        value = line->computeTree();
         std::cout << "Computed " << value << std::endl;
    }
    return 0;
}
