#include "ast.h"
#include "st.h"

using namespace AST;

extern ST::SymbolTable symtab;

/* Print methods */
void Integer::printTree(){
    std::cout << value;
    return;
}

void Variavel::printTree(){
    std::cout << name;
    return;
}

void BinOp::printTree(){
    left->printTree();
    switch(op){
        case plus: std::cout << " + "; break;
        case mult: std::cout << " * "; break;
        case assign: std::cout << " = "; break;
    }
    right->printTree();
    return;
}

void Block::printTree(){
    for (Node* line: lines) {
        line->printTree();
        std::cout << std::endl;
    }
}

/* Compute methods */
int Integer::computeTree(){
    return value;
}

int Variavel::computeTree(){
  return symtab.entryList[name].value;
}

int BinOp::computeTree(){
    int value, lvalue, rvalue;
    lvalue = left->computeTree();
    rvalue = right->computeTree();
    switch(op){
         case plus: value = lvalue + rvalue; break;
         case mult: value = lvalue * rvalue; break;
         case assign:
            Variavel* leftvar = dynamic_cast<Variavel*>(left);
            symtab.entryList[leftvar->name].value = rvalue;
            value = rvalue; break;
    }
    return value;
}

int Block::computeTree(){
    int value;
    for (Node* line: lines) {
        value = line->computeTree();
         std::cout << "Computed " << value << std::endl;
    }
    return 0;
}
