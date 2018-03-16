#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckEXP(SymbolTable* symbolTable, EXP* expression){
  if (debug){
    printf("EXP KIND: %i\n", expression->kind);
  }
  int x,y;
  switch (expression->kind) {
    case equaltoK:
      x = typeCheckEXP(symbolTable, expression->val.equaltoE.left);
      y = typeCheckEXP(symbolTable, expression->val.equaltoE.right);
      if (x == y ){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case nequaltoK:
      x = typeCheckEXP(symbolTable, expression->val.nequaltoE.left);
      y = typeCheckEXP(symbolTable, expression->val.nequaltoE.right);
      if (x == y){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case andK:
      x = typeCheckEXP(symbolTable, expression->val.andE.left);
      y = typeCheckEXP(symbolTable, expression->val.andE.right);
      if (x == y == BOOLEAN){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case smallerK:
      x = typeCheckEXP(symbolTable, expression->val.smallerE.left);
      y = typeCheckEXP(symbolTable, expression->val.smallerE.right);
      if (x == y == INTEGER){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case biggerK:
      x = typeCheckEXP(symbolTable, expression->val.biggerE.left);
      y = typeCheckEXP(symbolTable, expression->val.biggerE.right);
      if (x == y == INTEGER){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case smalequalK:
      x = typeCheckEXP(symbolTable, expression->val.smalequalE.left);
      y = typeCheckEXP(symbolTable, expression->val.smalequalE.right);
      if (x == y == INTEGER){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case bigequalK:
      x = typeCheckEXP(symbolTable, expression->val.bigequalE.left);
      y = typeCheckEXP(symbolTable, expression->val.bigequalE.right);
      if (x == y == INTEGER){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case moduloK:
      x = typeCheckEXP(symbolTable, expression->val.moduloE.left);
      y = typeCheckEXP(symbolTable, expression->val.moduloE.right);
      if (x == y == INTEGER){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case timesK:
      x = typeCheckEXP(symbolTable, expression->val.timesE.left);
      y = typeCheckEXP(symbolTable, expression->val.timesE.right);
      if (x == y == INTEGER){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case divK:
      x = typeCheckEXP(symbolTable, expression->val.divE.left);
      y = typeCheckEXP(symbolTable, expression->val.divE.right);
      if (x == y == INTEGER){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case plusK:
      x = typeCheckEXP(symbolTable, expression->val.plusE.left);
      y = typeCheckEXP(symbolTable, expression->val.plusE.right);
      if (x == y == INTEGER){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case minusK:
      x = typeCheckEXP(symbolTable, expression->val.minusE.left);
      y = typeCheckEXP(symbolTable, expression->val.minusE.right);
      if (x == y == INTEGER){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    case termK:
      return typeCheckTERM(symbolTable, expression->val.termE);
      break;

    case orK:
      x = typeCheckEXP(symbolTable, expression->val.orE.left);
      y = typeCheckEXP(symbolTable, expression->val.orE.right);
      if (x == y == BOOLEAN){
        return x;
      }else{
        printf("ERROR\n");
        return -1;
      }
      break;

    default:
      printf("default case in typeCheckEXP\n");
      break;
  }

  return 0;
}
