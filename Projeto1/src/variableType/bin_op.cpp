#include "variables.h"
#include "../symbolTable/symbolTable.h"

using namespace VAR;

extern ST::SymbolTable symtab;

void BinOp::printTree(){
  switch(op){
    case T_PLUS:
      left->printTree();
      std::cout << " (soma ";
      left->printType(Genre::FEM);
      std::cout << ") ";
      right->printTree();
      break;
    case T_SUB:
      if(left){
        left->printTree();
        std::cout << " (subtracao ";
        left->printType(Genre::FEM);
      }else{
        std::cout << " (menos unario ";
        right->printType(Genre::MASC);
      }
      std::cout << ") ";
      right->printTree();
      break;
    case T_MULT:
      left->printTree();
      std::cout << " (multiplicacao ";
      left->printType(Genre::FEM);
      std::cout << ") ";
      right->printTree();
      break;
    case T_DIV:
      left->printTree();
      std::cout << " (divisao ";
      right->printType(Genre::FEM);
      std::cout << ") ";
      right->printTree();
      break;
    case T_ASSIGN:
      std::cout << "Atribuicao de valor para ";
      left->printTree();
      std::cout << ": ";
      right->printTree();
      break;

    case T_EQUALS:
      left->printTree();
      std::cout << " (igual ";
      right->printType(Genre::MASC);
      std::cout << ") ";
      right->printTree();
      break;
    case T_NEQUALS:
      left->printTree();
      std::cout << " (diferente ";
      right->printType(Genre::MASC);
      std::cout << ") ";
      right->printTree();
      break;
    case T_BIGGEST:
      left->printTree();
      std::cout << " (maior ";
      right->printType(Genre::MASC);
      std::cout << ") ";
      right->printTree();
      break;
    case T_SMALLEST:
      left->printTree();
      std::cout << " (menor ";
      right->printType(Genre::MASC);
      std::cout << ") ";
      right->printTree();
      break;
    case T_BIGOREQUALS:
      left->printTree();
      std::cout << " (maior ou igual ";
      right->printType(Genre::MASC);
      std::cout << ") ";
      right->printTree();
      break;
    case T_SMALLOREQUALS:
      left->printTree();
      std::cout << " (menor ou igual ";
      right->printType(Genre::MASC);
      std::cout << ") ";
      right->printTree();
      break;

    case T_AND:
      left->printTree();
      std::cout << " (e ";
      right->printType(Genre::MASC);
      std::cout << ") ";
      right->printTree();
      break;
    case T_OR:
      left->printTree();
      std::cout << " (ou ";
      right->printType(Genre::MASC);
      std::cout << ") ";
      right->printTree();
      break;
    case T_NOT:
      std::cout << " (nao ";
      right->printType(Genre::MASC);
      std::cout << ") ";
      right->printTree();
      break;
  }
  return;
}

void BinOp::printType(Genre genre){
  if(left){
    left->printType(genre);
  }else{
    right->printType(genre);
  }
}
