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
  int i=0;
  for(i; i < strlen(str) ;i++ ){//iterating over the whole string
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

  // putSymbol takes a hash table and a string, name, as arguments and inserts
  // name into the hash table together with the associated value value. A pointer
  // to the SYMBOL value which stores name is returned.

  int hashValue;
  hashValue = Hash(name);

  Symbol *symbol = (Symbol *) malloc(sizeof(Symbol));
  symbol->name = name;
  symbol->value = value;
  symbol->next = NULL;

  if(t->table[hashValue] != NULL){
    Symbol *current = t->table[hashValue];
    while(current->next != NULL){
      if (current)
      current = current->next;
    }
    current->next = symbol;
  }
<<<<<<< HEAD
  else {
    t->table[hashValue] = symbol;
=======
  else {  //Collision, we check if the name matches any of the linked symbols
    Symbol *currentSymbol;
    currentSymbol = t->table[hashValue];
    while(currentSymbol != NULL){
      if(currentSymbol->name == name){
        currentSymbol->value = value;

        free(symbol);
        return currentSymbol;
      }
    currentSymbol = currentSymbol->next;
    }
>>>>>>> da3418049b904674d125e9c22c624c5fa588fce0
  }
  return symbol;
}

Symbol *getSymbol(SymbolTable *table, char *name){

  // getSymbol takes a hash table and a string name as arguments and searches for
  // name in the following manner: First search for name in the hash table which
  // is one of the arguments of the function call. If name is not there, continue the
  // search in the next hash table. This process is repeatedly recursively. If name has
  // not been found after the root of the tree (see Fig. 1) has been checked, the result
  // NULL is returned. If name is found, return a pointer to the SYMBOL value in
  // which name is stored.
  int hashed;
  Symbol *symbol;
  //printf("hej1\n");
  if(table->next !=NULL){

    //printf("hej2\n");
    symbol = getSymbol(table->next, name);
    if (symbol != NULL){
      return symbol;
    }
  }

  //printf("hej3\n");
  hashed = Hash(name);

  if(table->table[hashed] == NULL){

    //printf("hej4\n");
    return NULL;
  }else{

    //printf("hej5\n");
    symbol = table->table[hashed];
    while(symbol != NULL){

      //printf("hej6\n");
      if(symbol->name == name){
        return symbol;
      }
      symbol = symbol->next;
    }
    return NULL;
  }
  if(table->next !=NULL){

    //printf("hej2\n");
    symbol = getSymbol(table->next, name);
    if (symbol != NULL){
      return symbol;
    }
  }
  return NULL;

}

void dumpSymbolTable(SymbolTable *table){//DOES NOT WORK!
  // dumpSymbolTable takes a pointer to a hash table t as argument and prints all
  // the (name, value) pairs that are found in the hash tables from t up to the root.
  // Hash tables are printed one at a time. The printing should be formatted in a nice
  // way and is intended to be used for debugging (of other parts of the compiler).

  // int i;
  // for (i = 0; i < HashSize; i++){
  //   if (t->table[i] != NULL){
  //     printf("Pair = (%s, %i)\n", t->table[i]->name, t->table[i]->value);
  //   }
  //   else {
  //   }
  // }

  int i = 0;
  if (table->next != NULL) {
    dumpSymbolTable(table->next);
  }
  for(i;i<HashSize;i++){
    Symbol* symbol;
    Symbol* temp;
    if(t->table[i] != NULL){
        symbol = table->table[i];
        while(symbol->next != NULL){
          temp = symbol->next;
          printf("found symbol%s %d at %d\n",symbol->name, symbol->value, i);
          //free(s);
          symbol = temp;
        }
    }
  }
}
