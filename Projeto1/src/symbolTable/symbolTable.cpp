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
  VAR::Variable* nodeVar = dynamic_cast<VAR::Variable*>(node);
  do{
    symtab.entryList[nodeVar->name].type = t;
    if(nodeVar->next)
      nodeVar = dynamic_cast<VAR::Variable*>(nodeVar->next);
  }while(nodeVar->next);
  return nodeVar;
}
