#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckTERM(SymbolTable* symbolTable, TERM* term){
  switch (term->kind) {
    case numK:
      // printf("TERM numK\n");
      // printf("num is: %i\n", term->val.numT);
      break;

    default:
      printf("default case in typeCheckTERM\n");
      break;
  }
  return 0;
}
