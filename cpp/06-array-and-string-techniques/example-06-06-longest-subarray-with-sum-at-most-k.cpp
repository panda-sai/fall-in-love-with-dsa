// Fall in Love With DSA, Example 6.6: Longest subarray with sum at most K

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Works when all elements are non-negative.
int longestAtMostK(const vector<int>& arr, int K) {
    int n = arr.size();
    int left = 0, sum = 0, best = 0;
    for (int right = 0; right < n; right++) {
        sum += arr[right];               // grow
        while (sum > K) {                // shrink
            sum -= arr[left];
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    cout << longestAtMostK({2, 1, 3, 2, 1}, 5) << endl;
    cout << longestAtMostK({1, 2, 1, 0, 1, 1, 0}, 4)
         << endl;
    return 0;
}
