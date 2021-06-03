#include <stdio.h>

void swapper (int *array, int n) {
    int tmp = array[n];
    if (tmp < array[2 * n]) {
        array[n] = array[2 * n];
        array[2 * n] = tmp;
    }
    tmp = array[n];
    if (tmp < array[2 * n - 1]) {
        array[n] = array[2 * n - 1];
        array[2 * n - 1] = tmp;
    }
}

void heapSort (int *array, int arraySize) {
    int lastNum = arraySize - 1;
    while (lastNum > 0) {
        int root = lastNum / 2;
        while (root >= 1) {
            swapper(array, root);
            root--;
        }
        int temp = array[1];
        for (int i = 1; i < lastNum; i++) {
            array[i] = array[i + 1];
        }
        array[lastNum] = temp;
        lastNum--;
    }
}

int main () {
    int array[9] = {0, 4, -34274, -10, 2, 9, 99, 3, 5};
    int arraySize = sizeof(array) / sizeof(int);
    heapSort(array, arraySize);
    for (int i = 1; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

