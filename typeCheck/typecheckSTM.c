#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckSTM(SymbolTable* symbolTable, STM* statement){
  // printf("STM KIND: %i\n", statement->kind);
  Symbol* symbol;
  int typeCheck;
  switch (statement->kind) {
    case returnK:
      typeCheckEXP(symbolTable, statement->val.returnS);
      break;

    case writeK:
      typeCheckEXP(symbolTable, statement->val.writeS);
      break;

    case allocateK:
      typeCheckTYPE(symbolTable, statement->val.allocateS);
      break;

    case allocateoflengthK:
      typeCheckTYPE(symbolTable, statement->val.allocateoflengthS.variable);
      typeCheckEXP(symbolTable, statement->val.allocateoflengthS.expression);
      break;

    case assignK:
      typeCheckTYPE(symbolTable, statement->val.assignS.variable);
      if(statement->val.assignS.variable->kind != 0){
        printf("error\n");
        return -1;
      }
      symbol = getSymbol(symbolTable,statement->val.assignS.variable->val.idT);
      typeCheck = typeCheckEXP(symbolTable, statement->val.assignS.expression);
      if (symbol->type == typeCheck){
        return symbol->type;
      }else{
        printf("cant assign type %i to type %i\n", symbol->type, typeCheck);
      }
      break;

    case ifthenK:
      typeCheckEXP(symbolTable, statement->val.ifthenS.ifState);
      typeCheckSTM(symbolTable, statement->val.ifthenS.thenState);
      break;

    case ifelseK:
      typeCheckEXP(symbolTable, statement->val.ifelseS.ifState);
      typeCheckSTM(symbolTable, statement->val.ifelseS.thenState);
      typeCheckSTM(symbolTable, statement->val.ifelseS.elseState);
      break;

    case whileK:
      typeCheckEXP(symbolTable, statement->val.whileS.expression);
      typeCheckSTM(symbolTable, statement->val.whileS.statement);
      break;

    case stmlistK:
      typeCheckLIST(symbolTable, statement->val.stmlistS);
      break;

    default:
      printf("default case in typeCheckSTM\n");
      break;
  }
  return 0;
}
