#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckFUNC(FUNC* body, SymbolTable* symbolTable){
  typeCheckLIST(body->val.bodyF.decl_list, symbolTable);
  typeCheckLIST(body->val.bodyF.statement_list, symbolTable);

  return 0;
}
