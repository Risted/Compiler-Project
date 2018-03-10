#include <stdio.h>
#include "../headers/pretty.h"

void prettyDEC(DEC *d){
  switch (d->kind) {
    case listK:
      prettyLIST(d->val.listD);
      break;

    case dectypeK:
      printf("%s ", d->val.dectypeD.id);
      prettyTYPE(d->val.dectypeD.type);
      break;

    case decfuncK:
      prettyFUNC(d->val.decfuncD);
      break;

    default:
      printf("in default case in DEC\n");
      break;
  }
}
