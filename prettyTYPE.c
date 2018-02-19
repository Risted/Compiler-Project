#include <stdio.h>
#include "headers/pretty.h"

void prettyTYPE(TYPE *t){
   switch (t->kind) {
    case idK:
         printf("%s",t->val.idT);
         break;
    case intconstK:
         printf("%i",t->val.intconstT);
         break;
  }
}
