#include <stdio.h>
#include "../headers/pretty.h"

void prettyTYPE(TYPE *t){
   switch (t->kind) {
    case idK:
      printf("id %s ", t->val.idT);
      break;

    case intconstK:
      printf("int ");
      break;

    case boolK:
      printf("bool ");
      break;

    case arrayK:
      printf("array ");
      prettyTYPE(t->val.arrayT);
      break;

    case recordK:
      printf("record ");
      prettyLIST(t->val.recordT);
      break;

    case vareK:
      printf("vareK %s = ",t->val.vareT.id);
      prettyTYPE(t->val.vareT.variable);
      break;

    case varexpK:
      prettyTYPE(t->val.varexpT.variable);
      printf("= ");
      prettyEXP(t->val.varexpT.expression);
      break;

    case var_typeK:
      printf("typeK ");
      prettyTYPE(t->val.var_typeT.variable);
      printf("%s ", t->val.var_typeT.id);
      printf("\n");
      break;

    default:
      printf("in default case in TYPE\n");
      break;
  }
}
