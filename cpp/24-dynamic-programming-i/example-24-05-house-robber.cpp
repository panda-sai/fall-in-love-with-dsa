// Fall in Love With DSA, Example 24.5: House robber
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
int rob(const vector<int>& money) {
    int n = money.size();
    if (n == 0) return 0;
    int prev2 = 0, prev1 = 0;      // dp[i-2], dp[i-1]
    for (int i = 0; i < n; i++) {
        int curr = max(prev1, prev2 + money[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << rob({2, 7, 9, 3, 1}) << endl;
}
