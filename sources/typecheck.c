#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheck(FUNC* body, SymbolTable* symbolTable){
  SymbolTable* nextTable;
  LIST* list = body->val.bodyF.decl_list;
  LIST* stm_list = body->val.bodyF.statement_list;
  DEC* declaration;
  while(list != NULL){
    Symbol* newSymbol;
    int x;
    TYPE* type;
    declaration = list->val.decL.declaration;
    switch (declaration->kind) {
      case typeK:
        type = declaration->val.typeD.type;
        if(type->kind == intconstK){
          x = 0;
        }//TODO expand this if then statement
        newSymbol = putSymbol(symbolTable, declaration->val.typeD.id, x, NULL);
        break;
      case integerK:
        //newSymbol = putSymbol(symbolTable, declaration->val.integerE, INTEGER, NULL);
        //newSymbol = putSymbol(symbolTable, declaration->val.integerE, INTEGER, NULL);
        break;
/*      case stringK:
        newSymbol = putSymbol(symbolTable, declaration->val.stringE, STRING, NULL);
        break;*/
      case dectypeK:
        break;
      case decfuncK:
        newSymbol = putSymbol(symbolTable, declaration->val.stringE, FUNCTION, NULL);
        break;
      case listK:
        break;
      default:
        break;
        //printf("Compiler error, typechecker default%i\n",__line__);
    }
    list = list->val.decL.decl_list;

  }while(stm_list != NULL){
    //TODO here we update and scope symbol tables
    stm_list = stm_list->val.statelistL.statement_list;
  }

  //nextTable = decCheck(symbolTable, body->val.bodyF.statement_list->val.statelistL.statement);

  return 0;
}

SymbolTable* decCheck(SymbolTable* parent, STM* stm){
  printf("%i\n",stm->val.assignS.expression->val.termE->val.numT);

  SymbolTable* symbolTable = scopeSymbolTable(parent);

  return NULL;
}
