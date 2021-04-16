#include <stdio.h>
#include <stdlib.h>
#define N 6

int mySimpleSort (int *a) {
    int i = 0;
    int j;
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    return 0;
}

int main (void) {
    printf("\nstart\n");
    int i = 0;
    int a[N] = {1, -1, 54, 3, 5, 9};
    mySimpleSort(a);
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\nend\n");
}

