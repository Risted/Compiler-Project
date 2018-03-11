#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckFUNC(SymbolTable* symbolTable, FUNC* func){
  switch (func->kind) {
    case functionK:
      typeCheckFUNC(symbolTable, func->val.functionF.head);
      typeCheckFUNC(symbolTable, func->val.functionF.body);
      typeCheckFUNC(symbolTable, func->val.functionF.tail);
      break;

    case headK:
      //TODO: Add id
      typeCheckLIST(symbolTable, func->val.headF.par_decl_list);
      typeCheckTYPE(symbolTable, func->val.headF.type);
      break;

    case bodyK:
      typeCheckLIST(symbolTable, func->val.bodyF.decl_list);
      typeCheckLIST(symbolTable, func->val.bodyF.statement_list);
      break;

    case tailK:
      //TODO: add tailF get symbol
      break;
  }

  return 0;
}
