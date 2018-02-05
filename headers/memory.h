#ifndef MEMORY_H
#define MEMORY_H

void *Malloc(unsigned n);

#define NEW(type) (type *)Malloc(sizeof(type))

#endif
