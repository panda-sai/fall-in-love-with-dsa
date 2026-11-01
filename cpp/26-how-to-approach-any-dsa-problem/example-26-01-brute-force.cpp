// Fall in Love With DSA, Example 26.1: Brute force
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
int longestStreakBrute(const vector<int>& a, int k) {
    int n = a.size(), best = 0;
    for (int i = 0; i < n; i++) {
        int zeros = 0;
        for (int j = i; j < n; j++) {
            if (a[j] == 0) zeros++;
            if (zeros > k) break;
            best = max(best, j - i + 1);
        }
    }
    return best;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << longestStreakBrute({1, 1, 0, 0, 1, 1, 1, 0, 1, 1}, 2)
         << endl;
}
