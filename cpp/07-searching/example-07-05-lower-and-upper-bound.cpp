// Fall in Love With DSA, Example 7.5: Lower and upper bound

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// first index with arr[i] >= x  (n if none)
int lowerBound(const vector<int>& arr, int x) {
    int left = 0, right = arr.size();   // [left, right)
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= x) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    vector<int> arr = {10, 20, 20, 30, 40};
    for (int x : {20, 25}) {
        int lb = lowerBound(arr, x);
        int ub = upper_bound(arr.begin(), arr.end(), x)
                 - arr.begin();
        cout << "x = " << x << ": lower = " << lb
             << ", upper = " << ub
             << ", floor = " << arr[ub - 1]
             << ", ceiling = " << arr[lb] << endl;
    }
    return 0;
}
