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

  //Symbol *alsoNewSymbol;
  //alsoNewSymbol = putSymbol(newTable, string1, value1);

  Symbol *gitSymbol;
  gitSymbol = getSymbol(newTable,string);
  if(gitSymbol != NULL){
    printf("Symbol FOUND!: name: %s value:%d\n", gitSymbol->name,gitSymbol->value);
  }else{
    printf("No symbol found\n");
  }

  return 0;
}
