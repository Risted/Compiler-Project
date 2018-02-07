#include <stdio.h>
#include "headers/symbol.h"

int main(int argc, char const *argv[]) {

  char *string = "kitty";
  int value = 42;

  char *string1 = "kitty";
  int value1 = 9000;

  SymbolTable *newTable;
  newTable = initSymbolTable();

  Symbol *symbol;
  symbol = putSymbol(newTable, string, value);

  // printf("Symbol name: %s\n", symbol->name);
  // printf("Symbol value: %i\n", symbol->value);

  // printf("Value in newTable-table[199] before new symbol: %i\n", newTable->table[199]->value);

  Symbol *newSymbol;
  newSymbol = putSymbol(newTable, string1, value1);
  // printf("Value in newTable-table[199] after new symbol: %i\n", newTable->table[199]->value);

  Symbol *alsoNewSymbol;
  alsoNewSymbol = putSymbol(newTable, string1, value1);

  // Symbol *gitSymbol;
  // gitSymbol = getSymbol(newTable,string);
  // if(gitSymbol != NULL){
  //   printf("Symbol FOUND!: name: %s value:%d\n", gitSymbol->name,gitSymbol->value);
  // }else{
  //   printf("No symbol found\n");
  // }

  // dumpSymbolTable(newTable);

  return 0;
}
