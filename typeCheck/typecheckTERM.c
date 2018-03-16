#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int atoi (const char* str);

int typeCheckTERM(SymbolTable* symbolTable, TERM* term){
  if (debug){
    printf("TERM KIND: %i\n", term->kind);
  }
  int type;
  switch (term->kind) {
    case notK:
      type = typeCheckTERM(symbolTable, term->val.notT);
      if (type == INTEGER){
        return -1;
      }
      return BOOLEAN;
      break;

    case absoluteK:
      typeCheckEXP(symbolTable, term->val.absoluteT);
      break;

    case numK:
      //printf("its an int\n");
      return INTEGER;
      break;

    case expK:
      typeCheckEXP(symbolTable, term->val.expT);
      break;

    case booleanK:
      //printf("its a bool\n");
      return BOOLEAN;
      break;

    case variableK:
      typeCheckTYPE(symbolTable, term->val.variableT);
      break;

    case act_listK:
      typeCheckLIST(symbolTable, term->val.act_listT.act_list);
      //return atoi(term->val.act_listT.id);
      break;

    default:
      printf("default case in typeCheckTERM\n");
      break;
  }
  return 0;
}
