#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10

int seqSearch (vector<int> v, int target_number) {
    int array_length = v.size();
    int iterator = -1;
    while (iterator++ < array_length) {
        if (v[iterator] == target_number) {
            return iterator;
        }
    }
    return -1;
}

int factorial (int num) {
    if (num == 1) {
        return num;
    } else {
        return num * factorial(num - 1);
    }
}

int main () {
    vector<int> v;
    for (int i = 0; i < MAX; i++) {
        v.push_back(i);
    }
    int counter = 0;
    int fact = factorial(MAX);
    do {
        counter++;
        int target_index = seqSearch(v, 3);
        cout << "target_index: ";
        cout << target_index;
        cout << "; percentage: ";
        cout << 100.0 * (double)counter / (double)fact << endl;
    } while (next_permutation(v.begin(), v.end()));
}
