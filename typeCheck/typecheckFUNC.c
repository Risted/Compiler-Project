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
  typeCheckLIST(list,symbolTable);
while(stm_list != NULL){
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
