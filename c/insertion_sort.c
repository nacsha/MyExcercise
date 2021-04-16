#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 8

void swap (int *a, int *b) {
    int aval = *a;
    int bval = *b;
    *a = bval;
    *b = aval;
}

void myInsertionSort (int *a, int start, int end) {
    for (int i = start + 1; i < end; i++) {
        int tmp = a[i];
        int j;

        for (j = i - 1; j >= start; j--) {
            if (a[j] > tmp) a[j + 1] = a[j];
            else break;
        }
        a[j + 1] = tmp;
    }
}

int main (void) {
    printf("\nstart\n");
    int i = 0;
    int a[N] = {-1, 1, 54, 3, 5, 100, -3, 9};
    myInsertionSort(a, 0, N - 1);
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\nend\n");
}

// a result must be as follow
// -3, -1, 1, 3, 5, 9, 54, 100
