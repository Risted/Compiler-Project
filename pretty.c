#include <stdio.h>
#include "pretty.h"

void prettySTM(STM *stm) {
  switch (stm->kind) {
    case returnK:
      printf("return(");
      prettyEXP(stm->val.returnE);
      printf(")\n");
      break;
    case expK:
      prettyEXP(stm->val.expE);
      break;
    case writeK:
      printf("write(");
      prettyEXP(stm->val.returnE);
      printf(")\n");
      break;
  }
}
void prettyEXP(EXP *e)
{ switch (e->kind) {
    case idK:
         printf("%s",e->val.idE);
         break;
    case intconstK:
         printf("%i",e->val.intconstE);
         break;
    case equaltoK:
         printf("(");
         prettyEXP(e->val.equaltoE.left);
         printf("==");
         prettyEXP(e->val.equaltoE.right);
         printf(")");
         break;
    case nequaltoK:
         printf("(");
         prettyEXP(e->val.nequaltoE.left);
         printf("!=");
         prettyEXP(e->val.nequaltoE.right);
         printf(")");
         break;
    case andK:
         printf("(");
         prettyEXP(e->val.andE.left);
         printf("&&");
         prettyEXP(e->val.andE.right);
         printf(")");
         break;
    case smallerK:
         printf("(");
         prettyEXP(e->val.smallerE.left);
         printf("<");
         prettyEXP(e->val.smallerE.right);
         printf(")");
         break;
    case biggerK:
         printf("(");
         prettyEXP(e->val.biggerE.left);
         printf(">");
         prettyEXP(e->val.biggerE.right);
         printf(")");
         break;
    case smalequalK:
         printf("(");
         prettyEXP(e->val.smalequalE.left);
         printf("<=");
         prettyEXP(e->val.smalequalE.right);
         printf(")");
         break;
    case bigequalK:
         printf("(");
         prettyEXP(e->val.bigequalE.left);
         printf(">=");
         prettyEXP(e->val.bigequalE.right);
         printf(")");
         break;
    case timesK:
         printf("(");
         prettyEXP(e->val.timesE.left);
         printf("*");
         prettyEXP(e->val.timesE.right);
         printf(")");
         break;
    case divK:
         printf("(");
         prettyEXP(e->val.divE.left);
         printf("/");
         prettyEXP(e->val.divE.right);
         printf(")");
         break;
    case plusK:
         printf("(");
         prettyEXP(e->val.plusE.left);
         printf("+");
         prettyEXP(e->val.plusE.right);
         printf(")");
         break;
    case minusK:
         printf("(");
         prettyEXP(e->val.minusE.left);
         printf("-");
         prettyEXP(e->val.minusE.right);
         printf(")");
         break;
    case moduloK:
         printf("(");
         prettyEXP(e->val.moduloE.left);
         printf("%%");
         prettyEXP(e->val.moduloE.right);
         printf(")");
         break;
  }
}
