#include <stdio.h>
#include "tuple.h"

int intEquals(poly x, poly y){
    return *(int*)x == *(int*)y;
}

int charEquals(poly x, poly y){
    return *(char*)x == *(char*)y;
}

int floatEquals(poly x, poly y){
    return *(float*)x == *(float*)y;
}

void intOutPut(poly x){
    printf("%d", *(int*)x);
}

void charOutPut(poly x){
    printf("%c", *(char*)x);
}

void floatOutPut(poly x){
    printf("%f", *(float*)x);
}

int main(){
    int x = 5;
    char y = 'a';
    float z = 0.6777;

    tuple t1 = newTuple(&x, &y);
    tuple t2 = newTuple(&y, &z);

    if(tupleEquals(t1, t2, intEquals  , charEquals)){
        printf("Tuples are equal");
    }else {
        printf("tuples are different");
    }

    printf("\n");

    printf("t1:");
    tupleOutput(t1, intOutPut, charOutPut);
    printf("\n");

    printf("t2:");
    tupleOutput(t2, charOutPut, floatOutPut);
    printf("\n");

    freeTuple(t1);
    freeTuple(t2);
    return 0;
}