#include "../headers/symbol.h"
#include "../headers/memory.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int HashMod(int hash, int mod){
  hash = hash % mod;
  return hash
}

int Hash(char *str){
  int sum = 0;
  int i=0;
  for(i; i < strlen(str) ;i++ ){//iterating over the whole string
    sum = sum * 2 + str[i]; //we use decimal operaters since these are natively defined in c
  }
  return sum;
}

int Hashing(char *str, int mod){ //interface for our functions
  if(mod != HashSize){
    printf("you are not using the expected size %d\n", mod);
  }
  int x;
  x = Hash(str); //Calculating the hash value
  return(HashMod(x,mod));  //returns the
}

SymbolTable *initSymbolTable(){

  SymbolTable table = {
    .table = (struct SYMBOL *) malloc(HashSize * sizeof(SYMBOL *)),
    .next = NULL //we dont have a next so no need to make space for it.
  };

  // SYMBOL symbol = {
  //   .name = "Kitty",
  //   .value = 42,
  //   .next = NULL
  // };
  //
  // table.table[0] = &symbol;
  //
  // printf("table[0] name: %s\n", table.table[0]->name);

  printf("table address: %d\n", &table);

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
  int hashValue;
  hashValue = Hash(name);

  SYMBOL symbol = {
    .name = name,
    .value = value,
    .next = NULL
  };

  printf("---------> %s\n", symbol.name);
  printf("---------> %d\n", symbol.value);

  printf("Hash value: %i\n", hashValue);
  printf("address: %i\n", &symbol);

  // printf("table value: %dS\n", (int *)*t.table[hashValue]);

  // *t.table[hashValue] = &symbol;

  // if(t->table[hashValue] != NULL){
  //   printf("%d\n", __LINE__);
  //
  //   SYMBOL *current = t->table[hashValue];
  //
  //   while(current->next != NULL){
  //     printf("%d\n", __LINE__);
  //     current = current->next;
  //   }
  //
  //   current->next = &symbol;
  //
  // }
  // else {
  //   printf("%d\n", __LINE__);
  //   t->table[hashValue] = &symbol;
  // }
  printf("%d\n", __LINE__);

  return &symbol;

}

SYMBOL *getSymbol(SymbolTable *t, char *name){

  // getSymbol takes a hash table and a string name as arguments and searches for
  // name in the following manner: First search for name in the hash table which
  // is one of the arguments of the function call. If name is not there, continue the
  // search in the next hash table. This process is repeatedly recursively. If name has
  // not been found after the root of the tree (see Fig. 1) has been checked, the result
  // NULL is returned. If name is found, return a pointer to the SYMBOL value in
  // which name is stored.

}

void dumpSymbolTable(SymbolTable *t){

  // dumpSymbolTable takes a pointer to a hash table t as argument and prints all
  // the (name, value) pairs that are found in the hash tables from t up to the root.
  // Hash tables are printed one at a time. The printing should be formatted in a nice
  // way and is intended to be used for debugging (of other parts of the compiler).

}
