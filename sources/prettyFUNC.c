#include <stdio.h>
#include "../headers/pretty.h"

void prettyFUNC(FUNC *f){
  switch (f->kind) {
    case functionK:
      printf("function found on line:%d\n", f->lineno);
      prettyFUNC(f->val.functionF.head);
      prettyFUNC(f->val.functionF.body);
      prettyFUNC(f->val.functionF.tail);
      break;
    case headK:
      printf(" function %s ( ", f->val.headF.id);
      prettyLIST(f->val.headF.par_decl_list);
      prettyTYPE(f->val.headF.type);
      printf(")\n");
      break;
    case bodyK:
      prettyLIST(f->val.bodyF.decl_list);
      prettyLIST(f->val.bodyF.statement_list);
      break;
    case tailK:
      printf("end func: ");
      printf("%s\n", f->val.id);
      break;
  }
}
