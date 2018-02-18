#include <stdio.h>
#include "pretty.h"

void prettySTM(STM *s){
  switch (s->kind) {
    case returnK:
          printf("return");
          prettyEXP(s->val.returnS);
          break;
    case writeK:
          printf("write");
          prettyEXP(s->val.writeS);
          break;
   case allocateK:
          printf("allocating");
          prettyEXP(s->val.allocateS);
          break;
    case allocateoflengthK:
          printf("allocating:");
          prettyEXP(s->val.allocateoflengthS.variable);
          prettyEXP(s->val.allocateoflengthS.expression);
          break;
    case assignK:
          printf("assigning:");
          prettyEXP(s->val.assignS.variable);
          prettyEXP(s->val.assignS.expression);
          break;
    case ifthenK:
          printf("if(");
          prettyEXP(s->val.ifthenS.ifState);
          printf(")\n");
          printf("then(");
          prettySTM(s->val.ifthenS.thenState);
          printf(")\n");
          break;
    case ifelseK:
          printf("if(");
          prettyEXP(s->val.ifelseS.ifState);
          printf(")\n");
          printf("then(");
          prettySTM(s->val.ifelseS.thenState);
          printf(")\n");
          printf("else(");
          prettySTM(s->val.ifelseS.elseState);
          printf(")\n");
          break;
    case whileK:
          printf("while(");
          prettyEXP(s->val.whileS.expression);
          printf("){\n");
          printf("do:\n");
          prettySTM(s->val.whileS.statement);
          printf("end\n");
          printf("}\n");
          break;
  }
}

void prettyEXP(EXP *e){
   switch (e->kind) {
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
    case moduloK:
         printf("(");
         prettyEXP(e->val.moduloE.left);
         printf("%%");
         prettyEXP(e->val.moduloE.right);
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
  }
}
