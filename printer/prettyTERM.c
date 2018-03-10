#include <stdio.h>
#include "../headers/pretty.h"

void prettyTERM(TERM *t){
  switch (t->kind) {
    case notK:
        printf("not( ");
        prettyTERM(t->val.notT);
        printf(") " );
        break;

    case absoluteK:
        printf("| ");
        prettyEXP(t->val.absoluteT);
        printf("| ");
        break;

    case numK:
        printf("%d ",t->val.numT );
        break;

    case expK:
        prettyEXP(t->val.expT);
        break;

    case booleanK:
        if(t->val.booleanT == 0){
          printf("true ");
        }else if(t->val.booleanT == 1){
          printf("false ");
        }else{
          printf("NULL ");
        }
        break;

    case variableK:
        prettyTYPE(t->val.variableT);
        break;

    case act_listK:
        printf("%s ", t->val.act_listT.id);
        prettyLIST(t->val.act_listT.act_list);
        break;

    default:
        printf("in default case in TERM\n");
        break;
  }
}
