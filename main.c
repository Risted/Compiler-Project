#include <stdio.h>
#include "headers/symbol.h"

int main(int argc, char const *argv[]) {

  char *string = "kitty";
  int value = 21;

  // int result = Hash(string);
  // printf("String hash value: %i\n", result);

  SymbolTable* newTable;

  newTable = initSymbolTable();

  // printf("Size of table: %li\n", sizeof(newTable->table));

  SYMBOL *newSymbol;

  newSymbol = putSymbol(newTable, string, value);

  printf("Index kitty: %d\n", (newTable->table[199]->value));

  return 0;
}
