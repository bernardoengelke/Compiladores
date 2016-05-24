#include "symbolTable.h"

using namespace ST;

extern SymbolTable symtab;

VAR::Node* SymbolTable::newVariable(std::string id, VAR::Node* next){
    if ( checkId(id) ) yyerror("Variable redefinition! %s\n", id.c_str());
    else {
       Symbol entry(D_INTEGER, VARIABLE, 0, false);
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

VAR::Node* SymbolTable::updateTypeVariable(Type type, VAR::Node* root){
  VAR::Variable* varRoot = dynamic_cast<VAR::Variable*>(root);
  symtab.entryList[varRoot->name].type = type;

  while(varRoot->next){
    varRoot = dynamic_cast<VAR::Variable*>(varRoot->next);
    symtab.entryList[varRoot->name].type = type;
  }

  return varRoot;
}
