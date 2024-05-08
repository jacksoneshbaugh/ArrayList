#include "gtest/gtest.h"
#include <iostream>

extern "C" {
#include "../ArrayList.h"
}

// Unit tests for the ArrayList data structure
// Created by Jackson Eshbaugh on 07.05.2024.

TEST(ArrayListTest, testCreate) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);
    ASSERT_EQ(list->size, 0);
    ASSERT_EQ(list->capacity, 10);
    ASSERT_EQ(list->startingCapacity, 10);
    free(list);
}

TEST(ArrayListTest, testAddToBack) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);

    int element = 5;
    ASSERT_TRUE(arrayListAddToBack(list, &element));
    ASSERT_EQ(*(int *)((char *)list->array + 0 * list->elementSize), 5);

    int element2 = 10;
    ASSERT_TRUE(arrayListAddToBack(list, &element2));
    ASSERT_EQ(*(int *)((char *)list->array + 1 * list->elementSize), 10);

    free(list);
}

TEST(ArrayListTest, testAddToFront) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);

    int element = 5;
    ASSERT_TRUE(arrayListAddToFront(list, &element));
    ASSERT_EQ(*(int *)((char *)list->array + 0 * list->elementSize), 5);

    int element2 = 10;
    ASSERT_TRUE(arrayListAddToFront(list, &element2));
    ASSERT_EQ(*(int *)((char *)list->array + 0 * list->elementSize), 10);

    free(list);
}

TEST(ArrayListTest, testAdd) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);

    int element = 5;
    ASSERT_TRUE(arrayListAdd(list, 0, &element));
    ASSERT_EQ(*(int *)((char *)list->array + 0 * list->elementSize), 5);

    int element2 = 10;
    ASSERT_TRUE(arrayListAdd(list, 1, &element2));
    ASSERT_EQ(*(int *)((char *)list->array + 1 * list->elementSize), 10);

    int element3 = 15;
    ASSERT_TRUE(arrayListAdd(list, 1, &element3));
    ASSERT_EQ(*(int *)((char *)list->array + 1 * list->elementSize), 15);

    free(list);
}

TEST(ArrayListTest, testGet) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);

    int element = 5;
    ASSERT_TRUE(arrayListAdd(list, 0, &element));
    ASSERT_EQ(*(int *)((char *)list->array + 0 * list->elementSize), 5);

    int element2 = 10;
    ASSERT_TRUE(arrayListAdd(list, 1, &element2));
    ASSERT_EQ(*(int *)((char *)list->array + 1 * list->elementSize), 10);

    int element3 = 15;
    ASSERT_TRUE(arrayListAdd(list, 2, &element3));
    ASSERT_EQ(*(int *)((char *)list->array + 2 * list->elementSize), 15);

                      ASSERT_EQ(*(int *)arrayListGet(list, 0), 5);
                      ASSERT_EQ(*(int *)arrayListGet(list, 1), 10);
    ASSERT_EQ(*(int *)arrayListGet(list, 2), 15);
    ASSERT_EQ(arrayListGet(list, 3), nullptr);

    free(list);
}

TEST(ArrayListTest, testSet) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);

    int element = 5;
    ASSERT_TRUE(arrayListAdd(list, 0, &element));
    int element2 = 10;
    ASSERT_TRUE(arrayListAdd(list, 1, &element2));
    int element3 = 15;
    ASSERT_TRUE(arrayListAdd(list, 1, &element3));

    int element4 = 20;
    ASSERT_TRUE(arrayListSet(list, 0, &element4));
    ASSERT_EQ(*(int *)((char *)list->array + 0 * list->elementSize), 20);

    int element5 = 25;
    ASSERT_TRUE(arrayListSet(list, 1, &element5));
    ASSERT_EQ(*(int *)((char *)list->array + 1 * list->elementSize), 25);

    int element6 = 30;
    ASSERT_TRUE(arrayListSet(list, 2, &element6));
    ASSERT_EQ(*(int *)((char *)list->array + 2 * list->elementSize), 30);

                      ASSERT_FALSE(arrayListSet(list, 3, &element6));

            free(list);
}

TEST(ArrayListTest, testRemove) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);

    int element = 5;
    ASSERT_TRUE(arrayListAdd(list, 0, &element));
    int element2 = 10;
    ASSERT_TRUE(arrayListAdd(list, 1, &element2));
    int element3 = 15;
    ASSERT_TRUE(arrayListAdd(list, 1, &element3));

    ASSERT_EQ(*(int *)arrayListRemove(list, 0), 5);
    ASSERT_EQ(list->size, 2);
    ASSERT_EQ(*(int *)((char *)list->array + 0 * list->elementSize), 15);

    ASSERT_EQ(*(int *)arrayListRemove(list, 1), 10);
    ASSERT_EQ(list->size, 1);
    ASSERT_EQ(*(int *)((char *)list->array + 0 * list->elementSize), 15);

    ASSERT_EQ(*(int *)arrayListRemove(list, 0), 15);
    ASSERT_EQ(list->size, 0);

                      ASSERT_EQ(arrayListRemove(list, 0), nullptr);

            free(list);
}

TEST(ArrayListTest, testClear) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);

    int element = 5;
    ASSERT_TRUE(arrayListAdd(list, 0, &element));
    int element2 = 10;
    ASSERT_TRUE(arrayListAdd(list, 1, &element2));
    int element3 = 15;
    ASSERT_TRUE(arrayListAdd(list, 1, &element3));

    ASSERT_TRUE(arrayListClear(list));
    ASSERT_EQ(list->size, 0);
                      ASSERT_EQ(list->capacity, 10);
                      ASSERT_EQ(list->startingCapacity, 10);

                      free(list);
}

TEST(ArrayListTest, testResize) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);

    // Fill the list to initial capacity
    for (int i = 0; i < 10; ++i) {
        ASSERT_TRUE(arrayListAdd(list, i, &i));
    }

    int element = 10;
    ASSERT_TRUE(arrayListAdd(list, 10, &element));
    ASSERT_EQ(list->size, 11);
    ASSERT_EQ(list->capacity, 20);
    free(list);
}

TEST(ArrayListTest, testShrink) {
    ArrayList *list = arrayListCreate(10, sizeof(int));
    ASSERT_NE(list, nullptr);

    for (int i = 0; i < 15; ++i) {
        ASSERT_TRUE(arrayListAdd(list, i, &i));
    }

    // Remove elements to trigger shrink
    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(*(int *)arrayListRemove(list, 0), i);
    }

    ASSERT_EQ(list->size, 5);
    ASSERT_EQ(list->capacity, 10);  // Assuming shrink logic is triggered (shrinks to 1/2 of capacity)

    free(list);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}