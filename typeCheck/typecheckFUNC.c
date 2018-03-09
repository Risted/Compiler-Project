#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckFUNC(FUNC* body, SymbolTable* symbolTable){
  SymbolTable* nextTable;
  LIST* list = body->val.bodyF.decl_list;
  LIST* stm_list = body->val.bodyF.statement_list;
  DEC* declaration;
  STM* statement;
  while(list != NULL){
    Symbol* newSymbol;
    int decType;
    char *id;
    TYPE* type;
    declaration = list->val.decL.declaration;
    switch (declaration->kind) {
      case typeK:
        type = declaration->val.typeD.type;
        if(type->kind == intconstK){
          decType = INTEGER;
        }
        //TODO expand this if then statement
        newSymbol = putSymbol(symbolTable, declaration->val.typeD.id, decType, NULL);
        break;
      case integerK:
        //newSymbol = putSymbol(symbolTable, declaration->val.integerE, INTEGER, NULL);
        break;
/*      case stringK:
        newSymbol = putSymbol(symbolTable, declaration->val.stringE, STRING, NULL);
        break;*/
      case dectypeK:
        //putSymbol(symbolTable,declaration->val.)
        break;
      case decfuncK:
        id = declaration->val.func->val.functionF.head->val.headF.id;
        //TODO check if the above code could be done shorter
        newSymbol = putSymbol(symbolTable, id, FUNCTION, NULL);
        break;
      case listK:
        break;
      default:
      //printf("Compiler error, typechecker default%i\n",__line__);
        break;
    }
    list = list->val.decL.decl_list;
    declaration = list->val.decL.declaration;
  //TODO i would like an extra set of eyes to review this (Emil)
  //LIST* stm_list = body->val.bodyF.statement_list;
  }while(stm_list != NULL){
    statement =stm_list->val.statelistL.statement;
    //TODO here we update and scope symbol tables
    switch (statement->kind) {
      case returnK:
        //TODO check is legal expression typecheckEXP(statement->val.returnS);
        break;
      case writeK:
        typeCheckEXP(statement->val.writeS,symbolTable);
        //TODO we need to define what types can be used with write
        //what will we write here write(x||y); is it legal?
        break;
      case allocateK:
        //TODO the code below should be expanded into all the relevant kinds
        if(statement->val.allocateS->kind == idK){
          putSymbol(symbolTable,statement->val.allocateS->val.idT,INTEGER,NULL);
        }
        break;
      case allocateoflengthK:
        typeCheckTYPE(statement->val.allocateoflengthS.variable, nextTable);
        typeCheckEXP(statement->val.allocateoflengthS.expression, nextTable);
        break;
      case assignK:
        typeCheckTYPE(statement->val.assignS.variable, nextTable);
        break;
      case ifthenK:
        nextTable = scopeSymbolTable(symbolTable);
        typeCheckEXP(statement->val.ifthenS.ifState, nextTable);
        typeCheckSTM(statement->val.ifthenS.thenState, nextTable);
        break;
      case ifelseK:
        nextTable = scopeSymbolTable(symbolTable);
        typeCheckEXP(statement->val.ifelseS.ifState, nextTable);
        typeCheckSTM(statement->val.ifelseS.thenState, nextTable);
        typeCheckSTM(statement->val.ifelseS.elseState, nextTable);
        break;
      case whileK:
        nextTable = scopeSymbolTable(symbolTable);
        //TODO typecheck the new scope
        break;
      case stmlistK:
        break;
    }
    stm_list = stm_list->val.statelistL.statement_list;
  }
  return 0;
}
