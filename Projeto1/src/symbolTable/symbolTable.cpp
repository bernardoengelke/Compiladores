#include "symbolTable.h"

using namespace ST;

extern SymbolTable symtab;

VAR::Node* SymbolTable::newVariable(std::string id, VAR::Node* next){
    if ( checkId(id) ) yyerror("Variable redefinition! %s\n", id.c_str());
    else {
       Symbol entry(integer, variable, 0, false);
       addSymbol(id,entry); //Adds variable to symbol table
    }
    return new VAR::Variable(id, next); //Creates variable node anyway
}

VAR::Node* SymbolTable::assignVariable(std::string id){
    if ( ! checkId(id) ) yyerror("Variable not defined yet! %s\n", id.c_str());
    entryList[id].initialized = true;
    return new VAR::Variable(id, NULL); //Creates variable node anyway
}

VAR::Node* SymbolTable::useVariable(std::string id){
    if ( ! checkId(id) ) yyerror("Variable not defined yet! %s\n", id.c_str());
    if ( ! entryList[id].initialized ) yyerror("Variable not initialized yet! %s\n", id.c_str());
    return new VAR::Variable(id, NULL); //Creates variable node anyway
}

VAR::Node* updateTypeVariable(Type t, VAR::Node* node){
  while(node->next){
    symtab.entryList[node->id].type = t;
    node = node->next;
  }
  return node;
};
