// Fall in Love With DSA, Example 24.4: Fewest coins
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
int minCoins(const vector<int>& coins, int target) {
    const int INF = INT_MAX;
    vector<int> dp(target + 1, INF);
    dp[0] = 0;
    for (int a = 1; a <= target; a++) {
        for (int c : coins) {
            if (c <= a && dp[a - c] != INF)
                dp[a] = min(dp[a], dp[a - c] + 1);
        }
    }
    return dp[target] == INF ? -1 : dp[target];
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "coins {1, 3, 4}, target 6: " << minCoins({1, 3, 4}, 6)
         << endl;
    cout << "coins {2}, target 3: " << minCoins({2}, 3) << endl;
}
