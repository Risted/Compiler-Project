#include "../headers/symbol.h"
#include "../headers/memory.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int HashMod(int hash, int mod){
  hash = hash % mod;
  return hash
}


int Hash(char *str){
  int sum = 0;

  int i;
  for(i = 0; i < strlen(str) ;i++ ){
    sum = sum * 2 + str[i]; //we use decimal operaters since these are natively defined in c
  }
  //sum = sum % HashSize; //Takes the modulo of the sum and the hash table size.

  return sum;
}

int Hashing(char *str, int mod){
  int x;
  x = Hash(str);
  return(HashMod(x,mod));
}

SymbolTable *initSymbolTable(){
  SymbolTable table = {
    .table = Malloc(HashSize * sizeof(SYMBOL)),
    .next = NULL //we dont have a next so no need to make space for it.
  };


  return &table;
}

SymbolTable *scopeSymbolTable(SymbolTable *oldTable){
  SymbolTable table = {
    .table = Malloc(HashSize * sizeof(SYMBOL)),
    .next = oldTable
  };
  return &table;
}

SYMBOL *putSymbol(SymbolTable *t, char *name, int value){
  printf("%d\n", __LINE__);
  int hashValue;
  hashValue = Hash(name);

  SYMBOL symbol = {
    .name = name,
    .value = value,
    .next = NULL
  };
  printf("%d\n", __LINE__);
  printf("%d\n", t->table[hashValue]);

  if(t->table[hashValue] != NULL){
    printf("%d\n", __LINE__);

    SYMBOL *current = t->table[hashValue];

    while(current->next != NULL){
      printf("%d\n", __LINE__);
      current = current->next;
    }

    current->next = &symbol;

  }
  else {
    printf("%d\n", __LINE__);
    t->table[hashValue] = &symbol;
  }
  printf("%d\n", __LINE__);

  return &symbol;

}

SYMBOL *getSymbol(SymbolTable *t, char *name){

}

void dumpSymbolTable(SymbolTable *t){

}
