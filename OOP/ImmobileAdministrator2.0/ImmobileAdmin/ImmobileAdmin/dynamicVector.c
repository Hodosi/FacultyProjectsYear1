#define INIT_CAPACITY 1

#include "dynamicVector.h"
#include "stdlib.h"

DynamicVector* createDynamicVector() {

    DynamicVector *vector = malloc(sizeof(DynamicVector));
    vector -> items = (Element*)malloc(sizeof(Element) * INIT_CAPACITY);
    vector -> capacity = INIT_CAPACITY;
    vector -> length = 0;
    return vector;
}

void destroyDynamicVector(DynamicVector *vector) {
    free(vector -> items);
    free(vector);
}

void resize(DynamicVector *vector) {
    int new_capacity = 2 * vector -> capacity;

    Element *new_items = (Element*)malloc(sizeof(Element) * new_capacity);

    for (int i = 0; i < vector -> length; i++) {
        new_items[i] = vector -> items[i];
    }

    free(vector -> items);
    vector -> items = new_items;
    vector -> capacity = new_capacity;
}

void add(DynamicVector *vector, Element item) {
    if (vector -> length == vector -> capacity) {
        resize(vector);
    }
    vector -> items[vector -> length] = item;
    vector -> length++;
}