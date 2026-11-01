// Fall in Love With DSA, Example 25.3: 0/1 knapsack in one row
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
int knapsack1D(const vector<int>& wt,
               const vector<int>& val, int W) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < (int)wt.size(); i++)
        for (int w = W; w >= wt[i]; w--)  // R to L
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
    return dp[W];
}

// ---- a small test, so you can run this example ----
int main() {
    cout << knapsack1D({1, 3, 4, 5}, {1, 4, 5, 7}, 7) << endl;
}
