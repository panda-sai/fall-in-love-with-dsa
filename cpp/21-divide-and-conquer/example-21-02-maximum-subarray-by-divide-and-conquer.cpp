// Fall in Love With DSA, Example 21.2: Maximum subarray by divide and conquer
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// ---- code from the book ----
long long maxSub(const vector<int>& a, int l, int r) {
    if (l == r) return a[l];
    int m = l + (r - l) / 2;
    long long best = max(maxSub(a, l, m),
                         maxSub(a, m + 1, r));
    long long sum = 0, leftBest = LLONG_MIN;
    for (int i = m; i >= l; i--) {      // ends at m
        sum += a[i];
        leftBest = max(leftBest, sum);
    }
    sum = 0;
    long long rightBest = LLONG_MIN;
    for (int i = m + 1; i <= r; i++) {  // starts at m+1
        sum += a[i];
        rightBest = max(rightBest, sum);
    }
    return max(best, leftBest + rightBest);
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSub(a, 0, a.size() - 1) << endl;
}
