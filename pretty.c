#include <stdio.h>
#include "pretty.h"

void prettySTM(STM *s){
  switch (s->kind) {
    case returnK:
          printf("return(");
          prettyEXP(s->val.returnS);
          printf(")");
          break;
    case writeK:
          printf("write(");
          prettyEXP(s->val.writeS);
          printf(")");
          break;
   case allocateK:
          printf("allocating: ");
          prettyTYPE(s->val.allocateS);
          break;
    case allocateoflengthK:
          printf("allocating: ");
          prettyTYPE(s->val.allocateoflengthS.variable);
          prettyEXP(s->val.allocateoflengthS.expression);
          break;
    case assignK:
          printf("assigning: ");
          prettyTYPE(s->val.assignS.variable);
          prettyEXP(s->val.assignS.expression);
          break;
    case ifthenK:
          printf("if( ");
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
  }
}

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
void prettyEXP(EXP *e)
{ switch (e->kind) {
    case termK:
         prettyTERM(e->val.termE);
         break;
    case intconstK:
         prettyTERM(e->val.termE);
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
