// Fall in Love With DSA, Example 2.1: Counting comparisons in linear search

#include <iostream>
#include <vector>
using namespace std;

long long comparisons = 0;

int linearSearch(const vector<int>& arr, int key) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    for (int n : {10, 1000, 100000}) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = 2 * i;  // only even numbers
        }
        comparisons = 0;
        linearSearch(arr, 7);  // 7 is not present
        cout << "n = " << n << ", comparisons = "
             << comparisons << endl;
    }
    return 0;
}
