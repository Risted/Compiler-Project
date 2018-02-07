#include <stdio.h>
#include "headers/symbol.h"

int main(int argc, char const *argv[]) {

  char *string = "kitty";
  int value = 42;

  char *string1 = "kitty";
  int value1 = 9000;

  // int result = Hash(string);
  // printf("String hash value: %i\n", result);

  SymbolTable *newTable;
  SymbolTable *scopeTable;

  newTable = initSymbolTable();
  scopeTable=scopeSymbolTable(newTable);
  //printf("old:%d  new:%d\n",newTable, scopeTable->next);
  Symbol *newSymbol;
  newSymbol = putSymbol(newTable, string, value);
  printf("Value in newTable-table[199] before new symbol: %i\n", newTable->table[199]->value);

  Symbol *alsoNewSymbol;
  alsoNewSymbol = putSymbol(newTable, string1, value1);


  Symbol *gitSymbol;
  gitSymbol = getSymbol(newTable,string);
  if(gitSymbol != NULL){
    printf("Symbol FOUND!: name: %s value:%d\n", gitSymbol->name,gitSymbol->value);
  }else{
    printf("No symbol found\n");
  }

  printf("Value in newTable-table[199] after new symbol: %i\n", newTable->table[199]->value);

  // Symbol *gitSymbol;
  // gitSymbol = getSymbol(newTable,"bla");
  // if(gitSymbol != NULL){
  //   printf("%s %d\n", gitSymbol->name,gitSymbol->value);
  // }else{
  //   printf("mipmap\n");
  // }
>>>>>>> da3418049b904674d125e9c22c624c5fa588fce0

  return 0;
}
