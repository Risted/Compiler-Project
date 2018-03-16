#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

extern int debug;
int typeCheckSTM(SymbolTable* symbolTable, STM* statement){
  if (debug){
    printf("STM KIND: %i\n", statement->kind);
  }
  Symbol* symbol;
  SymbolTable* nextsymbolTable;
  int typeCheck = 5;
  TYPE* type;
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
      type = statement->val.assignS.variable;
      typeCheckTYPE(symbolTable, type);
      if(type->kind != 0 /*bad coding style i know but i like it*/){
        printf("error undefined assign variable \n");
        return -1;
      }
      symbol = getSymbol(symbolTable, type->val.idT);
      typeCheck = typeCheckEXP(symbolTable, statement->val.assignS.expression);
      if (symbol->type == typeCheck){
        return symbol->type;
      }else{
        printf("TYPE ERROR: cant assign type %i to type %i\n", symbol->type, typeCheck);
      }
      break;

    case ifthenK:
      typeCheckEXP(symbolTable, statement->val.ifthenS.ifState);
      nextsymbolTable = scopeSymbolTable(symbolTable);
      typeCheckSTM(nextsymbolTable, statement->val.ifthenS.thenState);
      break;

    case ifelseK:
      typeCheckEXP(symbolTable, statement->val.ifelseS.ifState);
      nextsymbolTable = scopeSymbolTable(symbolTable);
      typeCheckSTM(nextsymbolTable, statement->val.ifelseS.thenState);
      nextsymbolTable = scopeSymbolTable(symbolTable);
      typeCheckSTM(nextsymbolTable, statement->val.ifelseS.elseState);
      break;

    case whileK:
      typeCheckEXP(symbolTable, statement->val.whileS.expression);
      nextsymbolTable = scopeSymbolTable(symbolTable);
      typeCheckSTM(nextsymbolTable, statement->val.whileS.statement);
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
