#pragma once

#include <iostream>
#include <vector>

namespace VAR {

  //Binary operations
  enum Operation {
    T_PLUS,
    T_SUB,
    T_MULT,
    T_DIV,

    T_ASSIGN,

    T_EQUALS,
    T_NEQUALS,
    T_BIGGEST,
    T_SMALLEST,
    T_BIGOREQUALS,
    T_SMALLOREQUALS,

    T_AND,
    T_OR,
    T_NOT
  };

  enum Genre {
    MASC,
    FEM
  };

  class Node;

  typedef std::vector<Node*> NodeList;

  class Node {
    public:
      virtual ~Node() {}
      virtual void printTree(){}
      virtual void printType(Genre genre){}
  };

  class Integer : public Node {
    public:
      int value;
      Integer(int value) : value(value) {}
      void printTree();
      void printType(Genre genre);
  };

  class Real : public Node {
    public:
      float value;
      Real(float value) : value(value) {}
      void printTree();
      void printType(Genre genre);
  };

  class Bool : public Node {
    public:
      bool value;
      Bool(bool value) : value(value) {}
      void printTree();
      void printType(Genre genre);
  };

  class Variable : public Node {
    public:
      std::string name;
      Node *next;
      Variable(std::string name, Node *node) : name(name), next(node) {}
      void printTree();
      void printType(Genre genre);
      static void printTypeVariable(Node* node, Genre genre);
  };

  class Definition : public Node {
    public:
      Node *root;
      Definition(Node *node) : root(node) {}
      void printTree();
      void printListNameOfVariable(Variable* varNode);
  };

  class BinOp : public Node {
    public:
      Operation op;
      Node *left;
      Node *right;
      BinOp(Node *left, Operation op, Node *right) : left(left), right(right), op(op) {}
      void printTree();
      void printType(Genre genre);
  };

  class Block : public Node {
    public:
      NodeList lines;
      Block() {}
      void printTree();
  };
}
