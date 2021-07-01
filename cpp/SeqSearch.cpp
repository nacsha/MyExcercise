#include <iostream>
#include <vector>
using namespace std;

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

int main () {
    vector<int> v = {1, 2, 4, 6, 3, -2, 10};
    int target_index = seqSearch(v, 3);
    cout << "target_index: ";
    cout << target_index << endl;
}
