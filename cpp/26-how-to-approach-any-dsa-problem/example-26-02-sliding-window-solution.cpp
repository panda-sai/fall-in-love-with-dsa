// Fall in Love With DSA, Example 26.2: Sliding window solution
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
int longestStreak(const vector<int>& a, int k) {
    int n = a.size(), left = 0, zeros = 0, best = 0;
    for (int right = 0; right < n; right++) {
        if (a[right] == 0) zeros++;
        while (zeros > k) {  // too many flips
            if (a[left] == 0) zeros--;
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "example, k = 2: "
         << longestStreak({1, 1, 0, 0, 1, 1, 1, 0, 1, 1}, 2) << endl;
    cout << "all ones: " << longestStreak({1, 1, 1, 1, 1}, 0) << endl;
    cout << "all zeros, k = 0: " << longestStreak({0, 0, 0}, 0) << endl;
}
