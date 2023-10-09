
#ifndef TUPLE_H
#define TUPLE_H
#include <stdbool.h>

typedef void *poly;
typedef int (*tyEqFn) (poly, poly);
typedef void (*tyOutputFn) (poly);
typedef struct _tuple *tuple;//not same!
tuple newTuple (poly x, poly y);
poly first (tuple t);
poly second (tuple t);
int tupleEquals (tuple t1, tuple t2, tyEqFn eqx, tyEqFn eqy); //equality testing
void tupleOutput (tuple t, tyOutputFn outx, tyOutputFn outy);
void freeTuple(tuple t) ;

#endif