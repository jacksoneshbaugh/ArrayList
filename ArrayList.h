#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

// TODO: Add Element struct to store the element and the size/type of the element to make the ArrayList generic.

typedef struct {
    void *element;
    int size;
} Element;

typedef struct {
    void *array;
    int size;
    int elementSize;
    int capacity;
    int startingCapacity;
} ArrayList;

/**
 * @brief Create an ArrayList with a given capacity
 * @param capacity the initial capacity of the ArrayList
 * @param elementSize the size of the elements in the ArrayList
 * @return the created ArrayList
 */
ArrayList *arrayListCreate(int capacity, int elementSize);

/**
 * @brief Add an element to the end of the ArrayList
 * @param list the ArrayList to add the element to
 * @param element the element to add
 * @return {@code true} if add is successful, {@code false} otherwise
 */
bool arrayListAddToBack(ArrayList *list, void *element);

/**
 * @brief Add an element to the front of the ArrayList
 * @param list the ArrayList to add the element to
 * @param element the element to add
 * @return {@code true} if add is successful, {@code false} otherwise
 */
bool arrayListAddToFront(ArrayList *list, void *element);

/**
 * @brief Add an element to the ArrayList
 * @param list the ArrayList to add the element to
 * @param index the index to add the element to
 * @param element the element to add
 * @return {@code true} if add is successful, {@code false} otherwise
 */
bool arrayListAdd(ArrayList *list, int index, void *element);

/**
 * @brief Add an element to the ArrayList at a given index
 * @param list the ArrayList to get the element from
 * @param index the index to get the element at
 * @return the element at the given index, or {@code NULL} if there is an error
 */
void *arrayListGet(ArrayList *list, int index);

/**
 * @brief Set an element at a given index
 * @param list the ArrayList to set the element in
 * @param index the index to set the element at
 * @param element the element to set at the given index
 * @return {@code true} if set is successful, {@code false} otherwise
 */
bool arrayListSet(ArrayList *list, int index, void *element);

/**
 * @brief Remove an element at a given index
 * @param list the ArrayList to remove the element from
 * @param index the index to remove the element at
 * @return the removed element
 */
void *arrayListRemove(ArrayList *list, int index);

/**
 * @breif Clear the ArrayList
 * @param list the ArrayList to clear
 * @return {@code true} if clear is successful, {@code false} otherwise
 */
bool arrayListClear(ArrayList *list);

/**
 * @brief Free the memory of the ArrayList
 * @param list the ArrayList to free the memory of
 */
void arrayListFree(ArrayList *list);

#endif //ARRAYLIST_ARRAYLIST_H
