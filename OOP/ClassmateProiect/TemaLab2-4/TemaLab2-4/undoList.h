#pragma once


#include "MyList.h"

typedef void* Element;

typedef struct {
    Element *items;
    int length;
    int capacity;
} UndoList;

UndoList* createUndoList();

void destroyUndoList(UndoList*);

void addUndoList(UndoList*, Element);

Element undoUndoList(UndoList*);

