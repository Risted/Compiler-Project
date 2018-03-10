#include <stdio.h>
#include "../headers/pretty.h"

void prettySTM(STM *s){
  switch (s->kind) {
    case returnK:
      printf("return( ");
      prettyEXP(s->val.returnS);
      printf(") \n");
      break;

    case writeK:
      printf("write( ");
      prettyEXP(s->val.writeS);
      printf(") \n");
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
      printf("then( ");
      prettySTM(s->val.ifthenS.thenState);
      printf(")\n");
      break;

    case ifelseK:
      printf("if( ");
      prettyEXP(s->val.ifelseS.ifState);
      printf(")\n");
      printf("then( ");
      prettySTM(s->val.ifelseS.thenState);
      printf(")\n");
      printf("else( ");
      prettySTM(s->val.ifelseS.elseState);
      printf(")\n");
      break;

    case whileK:
      printf("while( ");
      prettyEXP(s->val.whileS.expression);
      printf("){\n");
      printf("do:\n");
      if(s->val.whileS.statement->kind == stmlistK){
        prettyLIST(s->val.whileS.statement->val.stmlistT);
      }else{
        prettySTM(s->val.whileS.statement);
      }
      printf("}end\n");
      break;

    case stmlistK:
      printf("prettySTM case stmlistK\n");
      break;

    default:
      printf("in default case in STM\n");
      break;
  }
}
