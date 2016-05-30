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
      case T_SUB: value = lvalue - rvalue; break;
      case T_MULT: value = lvalue * rvalue; break;
      case T_DIV: value = lvalue / rvalue; break;

      case T_ASSIGN: {
        Variable* leftVar = dynamic_cast<Variable*>(left);
        symtab.entryList[leftVar->name].value = rvalue;
        value = rvalue; break;
      }

      case T_EQUALS: value = lvalue == rvalue; break;
      case T_NEQUALS: value = lvalue != rvalue; break;
      case T_BIGGEST: value = lvalue > rvalue; break;
      case T_SMALLEST: value = lvalue < rvalue; break;
      case T_BIGOREQUALS: value = lvalue >= rvalue; break;
      case T_SMALLOREQUALS: value = lvalue <= rvalue; break;
      case T_AND: value = lvalue && rvalue; break;
      case T_OR: value = lvalue || rvalue; break;
      case T_NOT: std::cout << "not implemented"; break;
    }
    return value;
}
