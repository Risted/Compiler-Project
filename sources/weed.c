#include <stdio.h>
#include "../headers/weed.h"
#include "../headers/tree.h"

void* checkForFaultyFunction(FUNC* func){
  if (func->val.functionF.head->val.headF.id != func->val.functionF.tail->val.tailF){
    printf("function incorrectly structured- end does not match beginning.  %d\n",func->lineno);
  }else{

  }
}
void* checkForReturns(FUNC* func){
  int countingReturns = 1;
  LIST* listcopy = func->val.functionF.body->val.bodyF.statement_list;
  while(listcopy){
    if(listcopy->val.statelistL.statement->kind == ifthenK || listcopy->val.statelistL.statement->kind == ifelseK){
      countingReturns++;
    }
      if(listcopy->val.statelistL.statement->kind == returnK){
        countingReturns--;
      }
      listcopy = listcopy->val.statelistL.statement_list;

  }
  if (countingReturns !=0){
    printf("missing Return statements in function. %d\n",func->lineno);
  }
}

void* checkForDevideByZero(EXP* expression){
  int i =0;
  //dives into an expression tree and checks for aby division by zero
  //expression = findDevision(expression);
  if(expression != NULL){
    //i =evaluateDevident(expression);
    if (i == 0){
      printf("ERROR DEVISION BY ZERO %d\n",expression->lineno);
    }
  }
}

void* checkForTautaulogy(STM* stm){
  //like we saw in the lecture, if we see "something || true" we just compile
  //as if it was just "true" (or false)
  switch (stm->kind) {
    case ifthenK:
          EXPtautology(stm->val.ifthenS.ifState);
          break;
    case ifelseK:
          EXPtautology(stm->val.ifelseS.ifState);
          break;
  }
}
int EXPtautology(EXP *e){
  switch (e->kind) {
      case termK:
           //evalTERM(e->val.termE);
           break;
      case timesK:
           EXPtautology(e->val.timesE.left);
           EXPtautology(e->val.timesE.right);
           break;
      case divK:
           EXPtautology(e->val.divE.left);
           EXPtautology(e->val.divE.right);
           break;
      case plusK:
           EXPtautology(e->val.plusE.left);
           EXPtautology(e->val.plusE.right);
           break;
      case minusK:
           EXPtautology(e->val.minusE.left);
           EXPtautology(e->val.minusE.right);
           break;
      case moduloK:
           EXPtautology(e->val.moduloE.left);
           EXPtautology(e->val.moduloE.right);
           break;
      case biggerK:
            EXPtautology(e->val.biggerE.left);
            EXPtautology(e->val.biggerE.right);
            break;
      case smallerK:
            EXPtautology(e->val.smallerE.left);
            EXPtautology(e->val.smallerE.right);
            break;
      case equaltoK:
            EXPtautology(e->val.equaltoE.left);
            EXPtautology(e->val.equaltoE.right);
            break;
      case nequaltoK:
            EXPtautology(e->val.nequaltoE.left);
            EXPtautology(e->val.nequaltoE.right);
            break;
      case orK:
            EXPtautology(e->val.orE.left);
            EXPtautology(e->val.orE.right);
            break;
      case andK:
            EXPtautology(e->val.andE.left);
            EXPtautology(e->val.andE.right);
            break;
      case bigequalK:
            EXPtautology(e->val.bigequalE.left);
            EXPtautology(e->val.bigequalE.right);
            break;
      case smalequalK:
            EXPtautology(e->val.smalequalE.left);
            EXPtautology(e->val.smalequalE.right);
            break;
    }
}

int evaluateDevident(EXP* expression){
  //auxillary function for the devide by zero check
  //here we evaluate the expression to see if its expression evaluate to ZERO
  //if it does we return an error since that is not a defined expression

}

EXP* findDevision(EXP* expression){
  /*switch (e->kind) {
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
    }*/
    return NULL;
}
