#include <stdio.h>
#include "../headers/pretty.h"

void prettyLIST(LIST *l){
  switch (l->kind) {
    case parK:
      printf("parK\n");
      prettyLIST(l->val.parL);
      break;
    case varlistK:
      printf("varlistK\n");
      prettyTYPE(l->val.varlistL.var_type);
      prettyLIST(l->val.varlistL.var_decl_list);
      break;
  }
}
