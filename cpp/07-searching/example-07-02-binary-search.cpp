// Fall in Love With DSA, Example 7.2: Binary search

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;  // target is to the right
        } else {
            right = mid - 1;  // target is to the left
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72};
    cout << binarySearch(arr, 23) << endl;
    cout << binarySearch(arr, 10) << endl;
    return 0;
}
