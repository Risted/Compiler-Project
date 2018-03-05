#include "../headers/symbol.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheck(FUNC* body){
  SymbolTable* symbolTable = initSymbolTable();
  SymbolTable* nextTable;

  nextTable = decCheck(symbolTable, body->val.bodyF.statement_list->val.statelistL.statement);

  return 0;
}

SymbolTable* decCheck(SymbolTable* parent, STM* stm){
  printf("%i\n",stm->val.assignS.expression->val.termE->val.numT);

  SymbolTable* symbolTable = scopeSymbolTable(parent);

  return NULL;
}
