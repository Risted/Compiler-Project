#include "weed.h"
#include "tree.h"

checkForDevideByZero(EXP expression){
  int i;
  //dives into an expression tree and checks for aby division by zero
  expression = findDevision(expression);
  if(expression != NULL){
    i =evaluateDevident(expression);
    if (i == 0){
      printf("ERROR DEVISION BY ZERO %d\n",expression->lineno);
    }
  }
}

checkForTautaulogy(STM stm){
  //like we saw in the lecture, if we see "something || true" we just compile
  //as if it was just "true" (or false)

}

int evaluateDevident(EXP expression){
  //auxillary function for the devide by zero check
  //here we evaluate the expression to see if its expression evaluate to ZERO
  //if it does we return an error since that is not a defined expression

}

EXP findDevision(EXP expression){
  switch (e->kind) {
      case termK:
           return NULL;
           //findDevision(e->val.termE);
           break;
      case timesK:
           return findDevision(e->val.timesE.left);
           return findDevision(e->val.timesE.right);
           break;
      case divK:
           printf("found div statement at %d\n",e->lineno);
           return(e->val.divE.right);
           break;
      case plusK:
           return findDevision(e->val.plusE.left);
           return findDevision(e->val.plusE.right);
           break;
      case minusK:
           return findDevision(e->val.minusE.left);
           return findDevision(e->val.minusE.right);
           break;
      case moduloK:
           return findDevision(e->val.moduloE.left);
           return findDevision(e->val.moduloE.right);
           break;
      case biggerK:
            return findDevision(e->val.biggerE.left);
            return findDevision(e->val.biggerE.right);
            break;
      case smallerK:
            return findDevision(e->val.smallerE.left);
            return findDevision(e->val.smallerE.right);
            break;
      case equaltoK:
            return findDevision(e->val.equaltoE.left);
            return findDevision(e->val.equaltoE.right);
            break;
      case nequaltoK:
            return findDevision(e->val.nequaltoE.left);
            return findDevision(e->val.nequaltoE.right);
            break;
      case orK:
            return findDevision(e->val.orE.left);
            return findDevision(e->val.orE.right);
            break;
      case andK:
            return findDevision(e->val.andE.left);
            return findDevision(e->val.andE.right);
            break;
      case bigequalK:
            return findDevision(e->val.bigequalE.left);
            return findDevision(e->val.bigequalE.right);
            break;
      case smalequalK:
            return findDevision(e->val.smalequalE.left);
            return findDevision(e->val.smalequalE.right);
            break;
      return NULL;
    }
}
