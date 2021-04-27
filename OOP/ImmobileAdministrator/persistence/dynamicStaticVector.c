//
// Created by Hodosi on 3/7/2021.
//

#include "dynamicStaticVector.h"
#include <stdlib.h>


DynamicStaticVector* createDynamicStaticVector(){

    DynamicStaticVector* vector = (DynamicStaticVector*)malloc(sizeof(DynamicStaticVector));
    vector -> length = 0;
    vector -> capacity = 100;
    return vector;
}

void destroyDynamicStaticVector(DynamicStaticVector* vector){
    free(vector);
}

void addStatic(DynamicStaticVector* vector, Element item){
    if(vector -> length == vector -> capacity){
        return;
    }
    vector -> items[vector -> length] = item;
    vector -> length++;
}