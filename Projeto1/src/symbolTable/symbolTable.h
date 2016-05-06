/*Symbol Table definition*/
#pragma once

#include <map>
#include "../variableType/variables.h"

extern void yyerror(const char* s, ...);

namespace ST {

class Symbol;

enum Type { integer, real };
enum Kind { variable };

typedef std::map<std::string,Symbol> SymbolList; //Set of Symbols

class Symbol {
    public:
        Type type;              /*[Return] type of Symbol: integer, double.*/
        Kind kind;              /*Kind of symbol: variable, function, etc.*/
        int64_t value;        /*Space to store a value while we are doing interpretation.*/
        bool initialized;       /*Defines if symbol has been initialized or not.*/
        Symbol(Type type, Kind kind, int64_t value, bool initialized) :
            type(type), kind(kind), value(value), initialized(initialized) {  }
        Symbol() {type = integer; kind = variable; value = 0; initialized = false;}
};

class SymbolTable {
    public:
        SymbolList entryList;
        SymbolTable() {}
        /*checkId returns true if the variable has been defined and false if it does not exist*/
        bool checkId(std::string id) {return entryList.find(id) != entryList.end();}
        void addSymbol(std::string id, Symbol newsymbol) {entryList[id] = newsymbol;}
        VAR::Node* newVariable(std::string id, VAR::Node* next);
        VAR::Node* assignVariable(std::string id);
        VAR::Node* useVariable(std::string id);
        VAR::Node* updateTypeVariable(Type t, VAR::Node* raiz);
};

}
