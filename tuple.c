#include <stdio.h>
// This is the standard input-output header. Functions for file input and output, as well as for standard input and output (like printf, scanf, fopen, etc.), are declared in this header.
#include <stdlib.h>
#include "tuple.h"

struct _tuple{
    poly firstElement;
    poly secondElement;

};

tuple newTuple( poly x, poly y){
    tuple t = malloc(sizeof(*t));
    if (t == NULL) {
        // Handle memory allocation failure if necessary
        return NULL;
    }

    t->firstElement = x;
    t->secondElement = y;
    return t;
}

poly first(tuple t){
    return t->firstElement;
}

poly second(tuple t){
    return t->secondElement;
}

int tupleEquals(tuple t1, tuple t2, tyEqFn eqx, tyEqFn eqy){
    return eqx(t1->firstElement, t2->firstElement) && eqy(t1->secondElement,t2->secondElement);
}

void tupleOutput(tuple t, tyOutputFn outx, tyOutputFn outy){
    outx(t->firstElement);
    outy(t->secondElement);

}

void freeTuple(tuple t) {
    free(t);
}
