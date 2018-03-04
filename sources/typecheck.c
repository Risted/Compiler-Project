#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"

SymbolTable *initSymbolTable();

SymbolTable* typeCheck(FUNC* body){
  int val;
  SymbolTable* symboltable;
  symboltable = initSymbolTable;
  if(body->kind != bodyK){
    printf("compiler error\n");
    return NULL;
  }
  val = deepTypeCheck(body);
  if (val){
    return symboltable;
  }
  return val; //error code TODO define error codes

}

int deepTypeCheck(FUNC *function){
  LIST *var_decl_list = function->val.bodyF.decl_list;
  LIST *stm_list = function->val.bodyF.statement_list;
  DEC var_declaration;
  while (var_decl_list != NULL) {
    declaration = decl_list->val.decL.declaration;
    //type: tID\n tINT\n tARRAY tOF type\n tRECORD tOF tLBRACE var_decl_list tRBRACE \n
    //declaration : tTYPE tID tASSIGN type tSEMI\n function\n tVAR var_decl_list tSEMI\n
    if(declaration->kind == dectypeK){
      //what i mean to do here is trying to prevent a piece of code
      //like this: int a = 42, string b = a
      //but i cant seem to see where in the code i fix this =(
      if (declaration->val.typeD.type == NULL/*TODO find a value to compare*/){
        printf("type error %d\n", declaration->lineno);
      }

    }
    if(declaration->kind == decfuncK){
      declaration->val.func->scope = scopeSymbolTable(symboltable);
      //TODO fill the scope of the SymbolTable
    }
  }
  return 0;
}
