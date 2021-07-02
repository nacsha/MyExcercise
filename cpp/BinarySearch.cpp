#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <unistd.h>
using namespace std;

#define MAX 100

int bin_search(int begin, int end, vector <int> v, int target) {
    if (v[(begin + end) / 2] == target) {
        return (begin + end) / 2;
    } else if (end - begin <= 1) {
        if (v[begin] == target) {
            return begin;
        } else if (v[end] == target) {
            return end;
        } else {
            return -1;
        }
    }
    if (v[(begin + end) / 2] > target) {
        end = (begin + end) / 2;
    } else if (v[(begin + end) / 2] < target) {
        begin = (begin + end) / 2;
    }
    return bin_search(begin, end, v, target);
}

int my_rand (int min, int max) {
    return min + (int) (rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

int main (void) {
    vector <int> v;
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        v.push_back(my_rand(1, 100));
    }
    sort(v.begin(), v.end());

    int index = bin_search(0, v.size() - 1, v, MAX / 2);

    cout << "index: " << index << endl;
}
