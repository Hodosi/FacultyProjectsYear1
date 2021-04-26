#pragma once

/*
 * a pointer to anything
 */
typedef void* Element;

/*
 * define dynamic vector data type
 * (*items) - a pointer to an Element pointer list
 * length - the length of actual vector(the number of elements)
 *        - an integer
 * capacity - the max capacity of list
 *          - an integer
 */
typedef struct {
    Element *items;
    int length;
    int capacity;
} DynamicVector;

/*
 * create an empty dynamic vector
 * output: a pointer to a new dynamic vector
 */
DynamicVector* createDynamicVector();

/*
 * destroy a dynamic vector
 * input:  a pointer to an dynamic vector
 *         - the dynamic vector must be exists
 */
void destroyDynamicVector(DynamicVector*);

/*
 * add an element to the end of a dynamic vector
 * input:  a pointer to an dynamic vector
 *         - the dynamic vector must be exists
 *         an Element
 */
void add(DynamicVector*, Element);