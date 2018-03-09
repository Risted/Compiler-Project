#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckTYPE(TYPE* type, SymbolTable* symbolTable){
  switch (type->kind) {
    case intconstK:
      printf("intconstK\n");
      break;
    case idK:
      printf("idK\n");
      break;
    case boolK:
      printf("boolK\n");
      break;
    case arrayK:
      printf("arrayK\n");
      break;
    case recordK:
      printf("recordK\n");
      break;
    case vareK:
      printf("vareK\n");
      break;
    case varexpK:
      printf("varexpK\n");
      break;
  }
  return 0;
}
