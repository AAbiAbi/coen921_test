#include <stdio.h>
#include <stdlib.h>
#include "nTuple.h"

nTuple* createNTuple(int size) {
    nTuple* t = (nTuple *)malloc(sizeof(nTuple));
    t->elements = (Element *)malloc(size * sizeof(Element));
    //t->size = size;
    if (!t) return NULL;

    if (!t->elements) {
        free(t);
        return NULL;
    }

    for(int i = 0; i < size; i++) {
        t->elements[i].data = NULL;
        t->elements[i].type = INT; // default value
    }
    t->size = size;


    return t;
}

void setElement(nTuple *t, int index, void *data, DataType type) {

    if (index < 0 || index >= t->size) {
        fprintf(stderr, "Index out of bounds.\n");
        return;
    }

    t->elements[index].data = data;
    t->elements[index].type = type;
}

void* getElement(nTuple *t, int index) {

    if (index < 0 || index >= t->size) {
        fprintf(stderr, "Index out of bounds.\n");
        return NULL;
    }

    return t->elements[index].data;
}

DataType getType(nTuple *t, int index) {

    if (index < 0 || index >= t->size) {
        fprintf(stderr, "Index out of bounds.\n");
        return INT; // default value
    }

    return t->elements[index].type;
}

void freeNTuple(nTuple *t) {
    if (t) {
        if (t->elements) {
            free(t->elements);
        }
        free(t);
    }
}

int main() {
    nTuple *t = createNTuple(3);

    int x = 5;
    char y = 'a';
    float z = 0.99;

    setElement(t, 0, &x, INT);
    setElement(t, 1, &y, CHAR);
    setElement(t, 2, &z, FLOAT);

    // Add checks based on getType to correctly process/print the data
    printf("%d\n", *(int*)getElement(t, 0));
    printf("%c\n", *(char*)getElement(t, 1));
    printf("%f\n", *(float*)getElement(t, 2));

    freeNTuple(t);
    return 0;
}
