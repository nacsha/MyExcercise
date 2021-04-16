#include <stdio.h>
#include <stdlib.h>
#define N 6

// これまでの最小値とその位置を格納する構造体
struct mins {
    int pos;
    int val;
};

int mySelectSort (int *a) {
    int i = 0;
    int j = 0;
    for (i = 0; i < N - 1; i++) {
        struct mins min = {i, a[i]};  // i番目を仮の最小値とする
        for (j = i + 1; j < N; j++) { // i番目の1つ右から始める
            if (a[j] < min.val) {
                min.pos = j;
                min.val = a[min.pos];
            }
        }
        // i番目と、i+1番目以降の最小値を入れ替える
        // i番目がそのままの場合もある
        a[min.pos] = a[i];
        a[i] = min.val;
    }
    return 0;
}

int main (void) {
    printf("\nstart\n");
    int i = 0;
    int a[N] = {1, -1, 54, 3, 5, 9};
    mySelectSort(a);
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\nend\n");
}
