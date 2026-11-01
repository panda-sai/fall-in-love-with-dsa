// Fall in Love With DSA, Example 7.6: Search in a rotated sorted array

#include <iostream>
#include <vector>
using namespace std;

int searchRotated(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[left] <= arr[mid]) {  // left sorted
            if (arr[left] <= target
                && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {  // right sorted
            if (arr[mid] < target
                && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << searchRotated(arr, 0) << endl;
    cout << searchRotated(arr, 3) << endl;
    return 0;
}
