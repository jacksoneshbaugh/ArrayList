# ArrayList
A simple ArrayList implementation written in C and unit tested using Google Test.

## About

`ArrayList` is a simple implementation of a dynamic array in C. It is similar to Java's `ArrayList` class, and is designed to be easy to use and understand. The `ArrayList` struct contains a pointer to the array, the size of the array, the capacity of the array, and the size of each element in the array. The array is dynamically resized when the size of the array exceeds the capacity (or when most of the array is empty).

I created this project to begin applying what I learned in my Data Structures and Algorithms course to C, a language that I haven't worked with as much (and that the course I'll take next semester is taught using). I also wanted to learn how to use Google Test to write unit tests for my code.

## Usage
Simply include the header file in your project:
```c
#include "ArrayList.h"
```

## API

`ArrayList` exposes many functions similar to the ones found in Java's `ArrayList` class:

```c
ArrayList* arrayListCreate(int capacity, int elementSize);
bool arrayListAddToBack(ArrayList* arrayList, void* data);
bool arrayListAddToFront(ArrayList* arrayList, void* data);
bool arrayListAdd(ArrayList* arrayList, int index, void *data);
void *arrayListGet(ArrayList* arrayList, int index);
void *arrayListRemove(ArrayList* arrayList, int index);
bool arrayListSet(ArrayList* arrayList, int index, void *data);
void arrayListClear(ArrayList* arrayList);
void arrayListFree(ArrayList* arrayList);
```

To find the size of the `ArrayList`, use the `size` field:
```c
arrayList->size
```

## Example Usage

Below, we create an `ArrayList` of integers, add 10 integers to the back of the list, and then print them out:

```c
#include <stdio.h>
#include "ArrayList.h"

int main() {
    ArrayList* arrayList = arrayListCreate(10, sizeof(int));

    for (int i = 0; i < 10; i++) {
        arrayListAddToBack(arrayList, &i);
    }

    for (int i = 0; i < arrayList->size; i++) {
        printf("%d\n", *(int *) arrayListGet(arrayList, i));
    }

    arrayListFree(arrayList);
    return 0;
}
```

## Building

To build the project, run the following commands:

```bash
mkdir build
cd build
cmake ..
make
```