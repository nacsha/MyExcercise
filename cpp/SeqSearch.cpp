#include <iostream>
#include <array>
using namespace std;

int seqSearch (int array[], int target_number) {
    int array_length = *(&array + 1) - array;
    int iterator = -1;
    while (iterator++ < array_length) {
        if (array[iterator] == target_number) {
            return iterator;
        }
    }
    return -1;
}

int main () {
    int array[] = {1, 2, 4, 5, 3, 10, -3};
    int target_index = seqSearch(array, 3);
    cout << "target_index: ";
    cout << target_index;
}
