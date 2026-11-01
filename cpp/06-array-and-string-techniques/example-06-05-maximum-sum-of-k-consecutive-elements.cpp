// Fall in Love With DSA, Example 6.5: Maximum sum of k consecutive elements

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxSumK(const vector<int>& arr, int k) {
    int n = arr.size();
    if (k <= 0 || k > n) return -1;     // no window
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];             // first window
    }
    int best = windowSum;
    for (int right = k; right < n; right++) {
        windowSum -= arr[right - k];     // leaves
        windowSum += arr[right];         // enters
        best = max(best, windowSum);
    }
    return best;
}

int main() {
    cout << maxSumK({2, 1, 5, 1, 3, 2}, 3) << endl;
    return 0;
}
