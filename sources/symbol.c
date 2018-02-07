#include "../headers/symbol.h"
#include "../headers/memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int HashMod(int hash, int mod){
  hash = hash % mod;
  return hash;
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

  SymbolTable *table = (SymbolTable*)malloc(sizeof(SymbolTable));
  table->next = NULL; //we dont have a next so no need to make space for it.

  int i;
  for(i = 0; i < HashSize; i++){  //set all pointers to NULL, can probably be optimized
    table->table[i] = NULL;
  }

  return table;
}

SymbolTable *scopeSymbolTable(SymbolTable *oldTable){

  // scopeSymbolTable takes a pointer to a hash table t as argument and returns
  // a new hash table with a pointer to t in its next field

  SymbolTable *table = (SymbolTable *) malloc(sizeof(SymbolTable));

  table->next = oldTable;

  int i;
  for(i = 0; i < HashSize; i++){  //set all pointers to NULL, can probably be optimized
    table->table[i] = NULL;
  }

  return table;

  // SymbolTable table = {
  //   .table = Malloc(HashSize * sizeof(Symbol)),
  //   .next = oldTable
  // };
  // return &table;
}

Symbol *putSymbol(SymbolTable *t, char *name, int value){

  // putSymbol takes a hash table and a string, name, as arguments and inserts
  // name into the hash table together with the associated value value. A pointer
  // to the SYMBOL value which stores name is returned.

  int hashValue;
  hashValue = Hash(name);

  Symbol *symbol = (Symbol *) malloc(sizeof(Symbol));
  symbol->name = name;
  symbol->value = value;
  symbol->next = NULL;

  printf("Value in symbol: %i\n", symbol->value);

  // Symbol symbol = {
  //   .name = name,
  //   .value = value,
  //   .next = NULL
  // };

  if(t->table[hashValue] != NULL){
    printf("%d\n", __LINE__);

    Symbol *current = t->table[hashValue];

    while(current->next != NULL){
      current = current->next;
    }

    current->next = symbol;

  }
  else {
    printf("%d\n", __LINE__);
    t->table[hashValue] = symbol;
  }

  return symbol;

}

Symbol *getSymbol(SymbolTable *t, char *name){

  // getSymbol takes a hash table and a string name as arguments and searches for
  // name in the following manner: First search for name in the hash table which
  // is one of the arguments of the function call. If name is not there, continue the
  // search in the next hash table. This process is repeatedly recursively. If name has
  // not been found after the root of the tree (see Fig. 1) has been checked, the result
  // NULL is returned. If name is found, return a pointer to the SYMBOL value in
  // which name is stored.

  

  return NULL;

}

void dumpSymbolTable(SymbolTable *t){

  // dumpSymbolTable takes a pointer to a hash table t as argument and prints all
  // the (name, value) pairs that are found in the hash tables from t up to the root.
  // Hash tables are printed one at a time. The printing should be formatted in a nice
  // way and is intended to be used for debugging (of other parts of the compiler).

}
