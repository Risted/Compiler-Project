#include "../headers/symbol.h"
#include "../headers/typecheck.h"

SymbolTable *initSymbolTable();

SymbolTable* typeCheck(FUNC* body){
  SymbolTable* symboltable;
  symboltable = initSymbolTable;
  if(body->kind != bodyK){
    printf("compiler error\n");
    //return NULL;
  }
}
