#include <stdio.h>
#include "../headers/pretty.h"

void prettyEXP(EXP *e)
{ switch (e->kind) {
    case equaltoK:
      prettyEXP(e->val.equaltoE.left);
      printf("== ");
      prettyEXP(e->val.equaltoE.right);
    break;

    case nequaltoK:
      prettyEXP(e->val.nequaltoE.left);
      printf("!= ");
      prettyEXP(e->val.nequaltoE.right);
      break;

    case andK:
      prettyEXP(e->val.andE.left);
      printf("&& ");
      prettyEXP(e->val.andE.right);
      break;

    case smallerK:
      prettyEXP(e->val.smallerE.left);
      printf("< ");
      prettyEXP(e->val.smallerE.right);
      break;

    case biggerK:
       prettyEXP(e->val.biggerE.left);
       printf("> ");
       prettyEXP(e->val.biggerE.right);
       break;

    case smalequalK:
       prettyEXP(e->val.smalequalE.left);
       printf("<= ");
       prettyEXP(e->val.smalequalE.right);
       break;

    case bigequalK:
       prettyEXP(e->val.bigequalE.left);
       printf(">= ");
       prettyEXP(e->val.bigequalE.right);
       break;

     case moduloK:
       printf("( ");
       prettyEXP(e->val.moduloE.left);
       printf("%% ");
       prettyEXP(e->val.moduloE.right);
       printf(") ");
       break;

     case timesK:
       printf("( ");
       prettyEXP(e->val.timesE.left);
       printf("* ");
       prettyEXP(e->val.timesE.right);
       printf(") ");
       break;

     case divK:
       printf("( ");
       prettyEXP(e->val.divE.left);
       printf("/ ");
       prettyEXP(e->val.divE.right);
       printf(") ");
       break;

     case plusK:
       printf("( ");
       prettyEXP(e->val.plusE.left);
       printf("+ ");
       prettyEXP(e->val.plusE.right);
       printf(") ");
       break;

     case minusK:
       printf("( ");
       prettyEXP(e->val.minusE.left);
       printf("- ");
       prettyEXP(e->val.minusE.right);
       printf(") ");
       break;

    case termK:
       prettyTERM(e->val.termE);
       break;

    case orK:
       prettyEXP(e->val.orE.left);
       printf("|| ");
       prettyEXP(e->val.orE.right);
       break;

    default:
       printf("in default case in EXP\n");
       break;
  }
}
