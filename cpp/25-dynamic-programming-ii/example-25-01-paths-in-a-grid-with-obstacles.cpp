// Fall in Love With DSA, Example 25.1: Paths in a grid with obstacles
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
long long gridPaths(const vector<string>& g) {
    int R = g.size(), C = g[0].size();
    vector<vector<long long>> dp(
        R, vector<long long>(C, 0));
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (g[r][c] == '#') continue;  // blocked: 0
            if (r == 0 && c == 0) {
                dp[r][c] = 1;
                continue;
            }
            if (r > 0) dp[r][c] += dp[r - 1][c];
            if (c > 0) dp[r][c] += dp[r][c - 1];
        }
    }
    return dp[R - 1][C - 1];
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "3 x 7 open grid: "
         << gridPaths({".......", ".......", "......."}) << endl;
    cout << "3 x 3 with a blocked centre: "
         << gridPaths({"...", ".#.", "..."}) << endl;
}
