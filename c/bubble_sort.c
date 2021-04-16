#include <stdio.h>
#include <stdlib.h>
#define N 6

// ascending bubble sorting
void myBubbleSort (int *a, int start, int end) {
    for (int i = start; i <= end; i++) {
        for (int j = end; j > i; j--) {
            /* a[j - 1] should be less than a[j],
             * for ascending order */
            if (a[j - 1] > a[j]) {
                int tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }
    } 
}

int main (void) {
    printf("\nstart\n");
    int i = 0;
    int a[N] = {1, -1, 54, 3, 5, 9};
    myBubbleSort(a, 0, N - 1);
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\nend\n");
}

// a result must be as follow
// -1, 1, 3, 5, 9, 54
