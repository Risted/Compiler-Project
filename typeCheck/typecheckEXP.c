#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckEXP(SymbolTable* symbolTable, EXP* expression){
  switch (expression->kind) {
    case equaltoK:
      typeCheckEXP(symbolTable, expression->val.equaltoE.left);
      typeCheckEXP(symbolTable, expression->val.equaltoE.right);
      break;

    case nequaltoK:
      typeCheckEXP(symbolTable, expression->val.nequaltoE.left);
      typeCheckEXP(symbolTable, expression->val.nequaltoE.right);
      break;

    case andK:
      typeCheckEXP(symbolTable, expression->val.andE.left);
      typeCheckEXP(symbolTable, expression->val.andE.right);
      break;

    case smallerK:
      typeCheckEXP(symbolTable, expression->val.smallerE.left);
      typeCheckEXP(symbolTable, expression->val.smallerE.right);
      break;

    case biggerK:
      typeCheckEXP(symbolTable, expression->val.biggerE.left);
      typeCheckEXP(symbolTable, expression->val.biggerE.right);
      break;

    case smalequalK:
      typeCheckEXP(symbolTable, expression->val.smalequalE.left);
      typeCheckEXP(symbolTable, expression->val.smalequalE.right);
      break;

    case bigequalK:
      typeCheckEXP(symbolTable, expression->val.bigequalE.left);
      typeCheckEXP(symbolTable, expression->val.bigequalE.right);
      break;

    case moduloK:
      typeCheckEXP(symbolTable, expression->val.moduloE.left);
      typeCheckEXP(symbolTable, expression->val.moduloE.right);
      break;

    case timesK:
      typeCheckEXP(symbolTable, expression->val.timesE.left);
      typeCheckEXP(symbolTable, expression->val.timesE.right);
      break;

    case divK:
      typeCheckEXP(symbolTable, expression->val.divE.left);
      typeCheckEXP(symbolTable, expression->val.divE.right);
      break;

    case plusK:
      typeCheckEXP(symbolTable, expression->val.plusE.left);
      typeCheckEXP(symbolTable, expression->val.plusE.right);
      break;

    case minusK:
      typeCheckEXP(symbolTable, expression->val.minusE.left);
      typeCheckEXP(symbolTable, expression->val.minusE.right);
      break;

    case termK:
      typeCheckTERM(symbolTable, expression->val.termE);
      break;

    case orK:
      typeCheckEXP(symbolTable, expression->val.orE.left);
      typeCheckEXP(symbolTable, expression->val.orE.right);
      break;

    default:
      printf("default case in typeCheckEXP\n");
      break;
  }

  return 0;
}
