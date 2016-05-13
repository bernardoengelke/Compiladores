#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

extern ST::SymbolTable symtab;

void BinOp::printTree(){
    left->printTree();
    switch(op){
        case T_PLUS: std::cout << " + "; break;
        case T_SUB: std::cout << " - "; break;
        case T_MULT: std::cout << " * "; break;
        case T_DIV: std::cout << " / "; break;

        case T_ASSIGN: std::cout << " := "; break;

        case T_EQUALS: std::cout << " = "; break;
        case T_NEQUALS: std::cout << " ~= "; break;
        case T_BIGGEST: std::cout << " > "; break;
        case T_SMALLEST: std::cout << " < "; break;
        case T_BIGOREQUALS: std::cout << " >= "; break;
        case T_SMALLOREQUALS: std::cout << " <= "; break;

        case T_AND: std::cout << " AND "; break;
        case T_OR: std::cout << " OR "; break;
        case T_NOT: std::cout << " ~ "; break;
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

        case T_SUB: std::cout << "not implemented"; break;
        case T_MULT: std::cout << "not implemented"; break;
        case T_DIV: std::cout << "not implemented"; break;

        case T_ASSIGN: {
          Variable* leftVar = dynamic_cast<Variable*>(left);
          symtab.entryList[leftVar->name].value = rvalue;
          value = rvalue; break;
        }

        case T_EQUALS: std::cout << "not implemented"; break;
        case T_NEQUALS: std::cout << "not implemented"; break;
        case T_BIGGEST: std::cout << "not implemented"; break;
        case T_SMALLEST: std::cout << "not implemented"; break;
        case T_BIGOREQUALS: std::cout << "not implemented"; break;
        case T_SMALLOREQUALS: std::cout << "not implemented"; break;

        case T_AND: std::cout << "not implemented"; break;
        case T_OR: std::cout << "not implemented"; break;
        case T_NOT: std::cout << "not implemented"; break;
    }
    return value;
}
