#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckFUNC(SymbolTable* symbolTable, FUNC* func){
  typeCheckLIST(symbolTable, func->val.bodyF.decl_list);
  typeCheckLIST(symbolTable, func->val.bodyF.statement_list);

  return 0;
}
