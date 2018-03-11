#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckTERM(SymbolTable* symbolTable, TERM* term){
  switch (term->kind) {
    case notK:
      typeCheckTERM(symbolTable, term->val.notT);
      break;

    case absoluteK:
      typeCheckEXP(symbolTable, term->val.absoluteT);
      break;

    case numK:
      //TODO: how to do this
      break;

    case expK:
      typeCheckEXP(symbolTable, term->val.expT);
      break;

    case booleanK:
      //TODO: how to do this
      break;

    case variableK:
      typeCheckTYPE(symbolTable, term->val.variableT);
      break;

    case act_listK:
      //TODO: how to write id
      typeCheckLIST(symbolTable, term->val.act_listT.act_list);
      break;

    default:
      printf("default case in typeCheckTERM\n");
      break;
  }
  return 0;
}
