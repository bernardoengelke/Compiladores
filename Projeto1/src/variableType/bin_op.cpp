#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

extern ST::SymbolTable symtab;

void BinOp::printTree(){
  switch(op){
    case T_PLUS: std::cout << " + "; break;
    case T_SUB:
      if(left){
        std::cout << " subtração ";
      }else{
        std::cout << " unário ";
      }
      break;
    case T_MULT:
      std::cout << " * ";
      break;
    case T_DIV:
      std::cout << " / ";
      break;
    case T_ASSIGN:
      std::cout << "Atribuição de valor para ";
      left->printTree();
      std::cout << ": ";
      right->printTree();
      break;

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
  return;
}
