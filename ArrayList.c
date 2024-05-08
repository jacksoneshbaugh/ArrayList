#include "ArrayList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool resize(ArrayList *list, int newCapacity) {
    void *newArray = malloc(newCapacity * list->elementSize);
    if (newArray == NULL) {
        return false;
    }

    memcpy(newArray, list->array, list->size * list->elementSize);
    free(list->array);
    list->array = newArray;
    list->capacity = newCapacity;
    return true;
}

ArrayList *arrayListCreate(int capacity, int elementSize) {
    ArrayList *list = malloc(sizeof(ArrayList));
    if (list == NULL) {
        return NULL;
    }

    list->array = malloc(capacity * elementSize);
    if (list->array == NULL) {
        free(list);
        return NULL;
    }

    list->size = 0;
    list->capacity = capacity;
    list->startingCapacity = capacity;
    list->elementSize = elementSize;

    return list;
}

bool arrayListAddToBack(ArrayList *list, void *element) {
    return arrayListAdd(list, list->size, element);
}

bool arrayListAddToFront(ArrayList *list, void *element) {
    return arrayListAdd(list, 0, element);
}

bool arrayListAdd(ArrayList *list, int index, void *element) {
    if (index < 0 || index > list->size) {
        return false;
    }

    if (list->size == list->capacity) {
        if (!resize(list, 2 * list->capacity)) {
            return false;
        }
    }

    for (int i = list->size - 1; i >= index; --i) {
        memcpy((char *)list->array + (i + 1) * list->elementSize,
               (char *)list->array + i * list->elementSize, list->elementSize);
    }

    memcpy((char *)list->array + index * list->elementSize, element, list->elementSize);
    list->size++;
    return true;
}

void *arrayListGet(ArrayList *list, int index) {
    if (list == NULL || index < 0 || index >= list->size || list->array == NULL) {
        return NULL;
    }

    return (char *)list->array + index * list->elementSize;
}

bool arrayListSet(ArrayList *list, int index, void *element) {
    if (index < 0 || index >= list->size) {
        return false;
    }

    memcpy((char *)list->array + index * list->elementSize, element, list->elementSize);
    return true;
}

void *arrayListRemove(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }

    void *element = malloc(list->elementSize);
    if (element == NULL) {
        return NULL;
    }

    memcpy(element, (char *)list->array + index * list->elementSize, list->elementSize);

    for (int i = index; i < list->size - 1; ++i) {
        memcpy((char *)list->array + i * list->elementSize,
               (char *)list->array + (i + 1) * list->elementSize, list->elementSize);
    }

    list->size--;

    if (list->size <= list->capacity / 2 && list->capacity > list->startingCapacity) {
        resize(list, list->capacity / 2);
    }

    return element;
}

bool arrayListClear(ArrayList *list) {
    void *newArray = malloc(list->startingCapacity * list->elementSize);
    if (newArray == NULL) {
        return false;
    }

    free(list->array);
    list->array = newArray;
    list->capacity = list->startingCapacity;
    list->size = 0;
    return true;
}

void arrayListFree(ArrayList *list) {
    free(list->array);
    free(list);
}
