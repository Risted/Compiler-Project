#include <stdio.h>
#include "../headers/pretty.h"

void prettyDEC(DEC *d){
  switch (d->kind) {
    case integerK:
      printf("%d\n", d->val.integerE);
      break;
    case stringK:
      printf("%s\n", d->val.stringE);
      break;
    case decfuncK:
      prettyFUNC(d->val.func);
      break;
    case dectypeK:
      printf("%s\n", d->val.typeD.id);
      prettyTYPE(d->val.typeD.type);
      break;
    case listK:
      prettyLIST(d->val.listD);

  }
}
