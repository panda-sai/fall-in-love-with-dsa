// Fall in Love With DSA, Example 7.4: First and last occurrence

#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(const vector<int>& arr,
                    int target) {
    int left = 0, right = (int)arr.size() - 1;
    int answer = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            answer = mid;
            right = mid - 1;        // look further left
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

int lastOccurrence(const vector<int>& arr,
                   int target) {
    int left = 0, right = (int)arr.size() - 1;
    int answer = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            answer = mid;
            left = mid + 1;  // look further right
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 5};
    int first = firstOccurrence(arr, 2);
    int last = lastOccurrence(arr, 2);
    cout << "first = " << first << ", last = " << last
         << ", count = " << last - first + 1 << endl;
    return 0;
}
