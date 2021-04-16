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

int partialSort (int *a, int start, int end) {
    if (start == end) return start;

    int sign = (end - start) / abs(end - start);

    int last_changed = start;
    for (int i = start; sign * (i - end) < 0; i += sign) {
        if ((a[i] - a[i + sign]) * sign > 0) {
            swap(&a[i], &a[i + sign]);
            last_changed = i;
        }
    }
    return last_changed;
}

void myShakerSort (int *a, int start, int end) {
    int left = start;
    int right = end;
    while (left < right) {
        right = partialSort(a, left, right);
        left = partialSort(a, right, left);
    }
}

int main (void) {
    printf("\nstart\n");
    int i = 0;
    int a[N] = {1, -1, 54, 3, 5, 100, -3, 9};
    myShakerSort(a, 0, N - 1);
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\nend\n");
}

// a result must be as follow
// -3, -1, 1, 3, 5, 9, 54, 100
