#define INIT_CAPACITY 1

#include "undoList.h"
#include "MyList.h"
#include "produs.h"
#include "stdlib.h"


UndoList* createUndoList() {

    UndoList* vector = malloc(sizeof(UndoList));
    vector->items = (Element*)malloc(sizeof(Element) * INIT_CAPACITY);
    vector->capacity = INIT_CAPACITY;
    vector->length = 0;
    return vector;
}

void destroyUndoList(UndoList* undo_list) {
    for (int i = 0; i < undo_list->length; i++) {
        distrugereLista(undo_list->items[i]);
    }
    free(undo_list->items);
    free(undo_list);
}


void resizeUndo(UndoList* vector) {
    int new_capacity = 2 * vector->capacity;

    Produs** new_items = (Produs**)malloc(sizeof(Element) * new_capacity);

    for (int i = 0; i < vector->length; i++) {
        new_items[i] = vector->items[i];
    }

    free(vector->items);
    vector->items = new_items;
    vector->capacity = new_capacity;
}

void addUndoList(UndoList* vector, Element item_0) {
    MyList* cp_list = item_0;
    MyList* copy_item = copyList(cp_list);
    Element item = copy_item;
    if (vector->length == vector->capacity) {
        resizeUndo(vector);
    }
    vector->items[vector->length] = item;
    vector->length++;
}

Element undoUndoList(UndoList* vector) {
    if (vector->length == 0) {
        return NULL;
    }
    vector->length--;
    return vector->items[vector->length];
}


