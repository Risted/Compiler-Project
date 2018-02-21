#include <stdio.h>
#include "../headers/pretty.h"

void prettyTERM(TERM *t){
   switch (t->kind) {
    case idtypeK:
          printf("%s := ",t->val.idtypeT.id);
          prettyTYPE(t->val.idtypeT.type);
          break;
    case numK:
          printf("%d",t->val.numT );
          break;
    case notK:
          printf("not(");
          prettyTERM(t->val.notT);
          printf(")" );
          break;
    case expK:
          prettyEXP(t->val.expT);
          break;
    case absoluteK:
          printf("|");
          prettyEXP(t->val.absoluteT);
          printf("|");
    case booleanK:
          if(t->val.booleanT == 0){
            printf("True");
          }else if(t-val.booleanT == 1){
            printf("False");
          }else{
            printf("NULL");
          }
  }
}
