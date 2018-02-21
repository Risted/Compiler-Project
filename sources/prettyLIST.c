#include <stdio.h>
#include "../headers/pretty.h"

void prettyLIST(LIST *l){
  switch (l->kind) {
    case parK:
      prettyLIST(l->val.parL);
      break;

  }
}
