// Fall in Love With DSA, Example 25.2: 0/1 knapsack
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
int knapsack(const vector<int>& wt,
             const vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1,
                           vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            int skip = dp[i - 1][w];
            int take = -1;           // not possible
            int wi = wt[i - 1], vi = val[i - 1];
            if (wi <= w)
                take = vi + dp[i - 1][w - wi];
            dp[i][w] = max(skip, take);
        }
    }
    return dp[n][W];
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "rice, dal, spices, bag 50: "
         << knapsack({10, 20, 30}, {60, 100, 120}, 50) << endl;
    cout << "weights {1, 3, 4, 5}, values {1, 4, 5, 7}, bag 7: "
         << knapsack({1, 3, 4, 5}, {1, 4, 5, 7}, 7) << endl;
}
