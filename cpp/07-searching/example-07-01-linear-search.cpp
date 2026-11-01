// Fall in Love With DSA, Example 7.1: Linear search

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;        // not found
}

int main() {
    vector<int> arr = {12, 5, 8, 20, 15};
    cout << linearSearch(arr, 20) << endl;
    cout << linearSearch(arr, 7) << endl;
    return 0;
}
