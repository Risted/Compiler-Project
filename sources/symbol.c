#include "../headers/symbol.h"
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <math.h>

int convertBinaryToDecimal(long long n);

int Hash(char *str){

  int sum = 0;
  for(i = 0;i<len(str);i++){
    sum = sum*2+str[i]; //we use decimal operaters since these are natively defined in c
  }
  return sum;
}


SymbolTable *initSymbolTable(){
  SymbolTable x = {
    .table = Malloc(HashSize),
    .next = NULL //we dont have a next so no need to make space for it.
  };
  return x;
}

SymbolTable *scopeSymbolTable(SymbolTable *t){
  SymbolTable x = {
    .table = Malloc(HashSize),
    .next = t
  };
  return x;
}

SYMBOL *putSymbol(SymbolTable *t, char *name, int value){
  
}

SYMBOL *getSymbol(SymbolTable *t, char *name){

}

void dumpSymbolTable(SymbolTable *t){
}
