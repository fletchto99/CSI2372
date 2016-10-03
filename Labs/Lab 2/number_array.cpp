#include <iostream>

#include "number_array.h"

using namespace std;

int* findFirst(int value, int array[], int length) {
    for(int i = 0; i < length; i++) {
        if (value == array[i]) {
            return &array[i];
        }
    }
    return nullptr;
}

int** findAll(int value, int array[], int length, int& numFound) {
    for(int i = 0; i < length; i++) {
        if (value == array[i]) {
            numFound++;
        }
    }

    int **result = new int* [numFound];

    int idx = 0;

    for(int i=0; i < length; i++) {
        if (value == array[i]) {
            result[idx++] = &array[i];
        }
    }

    return result;
}

void printArray(int array[], int length) {
    cout << "[";
    for(int i = 0; i < length; i++) {
        if (i == length - 1) {
            cout << array[i] << " ";
        } else {
            cout << array[i] << ", ";
        }
    }
    cout << "]";
}

int* append(int(*arr)[4], int arr2[3]) {

    int *result = new int[7];

    int index = 0;

    for(auto i : (*arr)) {
        result[index++] = i;
    }

    for(size_t i = 0; i < 3; i++) {
        result[index++] = arr2[i];
    }

    return result;
}