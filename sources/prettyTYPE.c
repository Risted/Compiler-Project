#include <stdio.h>
#include "../headers/pretty.h"

void prettyTYPE(TYPE *t){
   switch (t->kind) {
    case idK:
         printf("id %s", t->val.idT);
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
         printf("vareK");
         break;
    case varexpK:
         printf("vareexpK");
         break;
  }
}
