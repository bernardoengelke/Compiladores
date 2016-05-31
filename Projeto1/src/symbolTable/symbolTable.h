#pragma once

#include <map>
#include "../variableType/variables.h"

extern void yyerror(const char* s, ...);

namespace ST {

class Symbol;

enum Type {
  D_INTEGER,
  D_REAL ,
  D_BOOLEAN,
  UNKNOWN
};

enum Kind {
  VARIABLE
};

typedef std::map<std::string,Symbol> SymbolList; //Set of Symbols

class Symbol {
    public:
        Type type;              /*[Return] type of Symbol: integer, double.*/
        Kind kind;              /*Kind of symbol: variable, function, etc.*/
        bool initialized;       /*Defines if symbol has been initialized or not.*/
        Symbol(Type type, Kind kind, bool initialized) :
            type(type), kind(kind), initialized(initialized) {  }
        Symbol() {type = UNKNOWN; kind = VARIABLE; initialized = false;}
};

class SymbolTable {
    public:
        SymbolList entryList;
        SymbolTable() {} /*checkId returns true if the variable has been defined and false if it does not exist*/
        bool checkId(std::string id) {return entryList.find(id) != entryList.end();}
        void addSymbol(std::string id, Symbol newsymbol) {entryList[id] = newsymbol;}
        VAR::Node* newVariable(std::string id, VAR::Node* next);
        VAR::Node* assignVariable(std::string id);
        VAR::Node* useVariable(std::string id);
        VAR::Node* updateTypeVariable(Type type, VAR::Node* root);
};

}
