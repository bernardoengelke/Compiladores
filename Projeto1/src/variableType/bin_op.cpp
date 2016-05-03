#include "variables.h"

using namespace VAR;

void BinOp::printTree(){
    left->printTree();
    switch(op){
        case T_PLUS: std::cout << " + "; break;
        // case mult: std::cout << " * "; break;
        // case assign: std::cout << " = "; break;
    }
    right->printTree();
    return;
}

int BinOp::computeTree(){
    int value, lvalue, rvalue;
    lvalue = left->computeTree();
    rvalue = right->computeTree();
    switch(op){
         case T_PLUS: value = lvalue + rvalue; break;
        //  case mult: value = lvalue * rvalue; break;
        //  case assign:
        //     Variavel* leftvar = dynamic_cast<Variavel*>(left);
        //     symtab.entryList[leftvar->name].value = rvalue;
        //     value = rvalue; break;
    }
    return value;
}
