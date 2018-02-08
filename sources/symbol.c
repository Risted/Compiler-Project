#include "../headers/symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*int HashMod(int hash, int mod){
  hash = hash % mod;
  return hash;
}*/

int Hash(char *str){
  int sum = 0;
  unsigned int i;
  for(i = 0; i < strlen(str) ;i++ ){//iterating over the whole string
    sum = sum * 2 + str[i]; //we use decimal operaters since these are natively defined in c
  }
  return sum % HashSize;
}

/*int Hashing(char *str, int mod){ //interface for our functions
  if(mod != HashSize){
    printf("you are not using the expected size %d\n", mod);
  }
  int x;
  x = Hash(str); //Calculating the hash value
  return(HashMod(x,mod));  //returns the
}*/

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

  SymbolTable *table;
  table = initSymbolTable();
  table->next = oldTable;
  return table;
}

Symbol *putSymbol(SymbolTable *t, char *name, int value){
  int hashValue;
  hashValue = Hash(name);

  Symbol *symbol = (Symbol *) malloc(sizeof(Symbol));
  symbol->name = name;
  symbol->value = value;
  symbol->next = NULL;

  if (t->table[hashValue] == NULL){
    t->table[hashValue] = symbol;

    return symbol;
  }
  else {
    Symbol *currentSymbol;
    currentSymbol = t->table[hashValue];
    while(currentSymbol != NULL){
      if(strcmp(currentSymbol->name, name) == 0){
        currentSymbol->value = value;

        free(symbol);
        return currentSymbol;
      }
      else {
        currentSymbol->next = symbol;

        return symbol;
      }
      currentSymbol = currentSymbol->next;
    }
  }
  return NULL;
}

Symbol *getSymbol(SymbolTable *table, char *name){

  // getSymbol takes a hash table and a string name as arguments and searches for
  // name in the following manner: First search for name in the hash table which
  // is one of the arguments of the function call. If name is not there, continue the
  // search in the next hash table. This process is repeatedly recursively. If name has
  // not been found after the root of the tree (see Fig. 1) has been checked, the result
  // NULL is returned. If name is found, return a pointer to the SYMBOL value in
  // which name is stored.
  int hashValue;
  Symbol *symbol;

  hashValue = Hash(name);

  if(table->table[hashValue] == NULL){

    return NULL;
  }else{

    symbol = table->table[hashValue];
    while(symbol != NULL){

      if(symbol->name == name){
        return symbol;
      }
      symbol = symbol->next;
    }
    return NULL;
  }
  if(table->next !=NULL){

    symbol = getSymbol(table->next, name);
    if (symbol != NULL){
      return symbol;
    }
  }
  return NULL;
}

void dropLinkedList(Symbol *symbol, int i){
  Symbol *currentSymbol;
  currentSymbol = symbol;
  while(currentSymbol != NULL){
    printf("Index %i = (%s, %i)\n", i, currentSymbol->name, currentSymbol->value);
    currentSymbol = currentSymbol->next;
  }
}

void dumpSymbolTable(SymbolTable *t){
  // dumpSymbolTable takes a pointer to a hash table t as argument and prints all
  // the (name, value) pairs that are found in the hash tables from t up to the root.
  // Hash tables are printed one at a time. The printing should be formatted in a nice
  // way and is intended to be used for debugging (of other parts of the compiler).
  printf("\n");
  printf("Start of table\n");

  int i;

  for (i = 0; i < HashSize; i++){
    if (t->table[i] != NULL){
      if (t->table[i]->next == NULL){
        printf("Index %i = (%s, %i)\n", i, t->table[i]->name, t->table[i]->value);
      }
      else {
        dropLinkedList(t->table[i], i);
      }
    }
  }
  if (t->next != NULL){
    dumpSymbolTable(t->next);
  }

}
