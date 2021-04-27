//
// Created by Hodosi on 3/7/2021.
//

#ifndef IMMOBILEADMINISTRATOR_DYNAMICSTATICVECTOR_H
#define IMMOBILEADMINISTRATOR_DYNAMICSTATICVECTOR_H

typedef void* Element;

typedef struct {
    Element items[100];
    int capacity;
    int length;
} DynamicStaticVector;

DynamicStaticVector* createDynamicStaticVector();

void destroyDynamicStaticVector(DynamicStaticVector*);

void addStatic(DynamicStaticVector*, Element);

#endif //IMMOBILEADMINISTRATOR_DYNAMICSTATICVECTOR_H
