#include <stdio.h>
#include <stdlib.h>
#ifndef NTUPLE_H
#define NTUPLE_H


typedef enum {
    INT, CHAR, FLOAT, //... add more as needed
} DataType;

typedef struct {
    void *data;
    DataType type;
} Element;

typedef struct {
    Element *elements;
    int size;
} nTuple;

nTuple* createNTuple(int size) ;

void setElement(nTuple *t, int index, void *data, DataType type) ;
   
void* getElement(nTuple *t, int index);
DataType getType(nTuple *t, int index) ;

void freeNTuple(nTuple *t) ;

#endif