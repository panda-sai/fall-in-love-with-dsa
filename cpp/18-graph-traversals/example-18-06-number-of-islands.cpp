// Fall in Love With DSA, Example 18.6: Number of islands
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

// ---- helpers used by the test below (not printed in the book) ----
vector<vector<int>> undirected(int n, vector<pair<int, int>> e) {
    vector<vector<int>> adj(n);
    for (auto [u, v] : e) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (auto& l : adj) sort(l.begin(), l.end());
    return adj;
}
vector<vector<int>> directed(int n, vector<pair<int, int>> e) {
    vector<vector<int>> adj(n);
    for (auto [u, v] : e) adj[u].push_back(v);
    return adj;
}
// A..G = 0..6: A-B A-C B-D B-E C-F E-G F-G
vector<vector<int>> sampleGraph() {
    return undirected(
        7, {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {4, 6}, {5, 6}});
}

// ---- code from the book ----
void sink(vector<string>& g, int r, int c) {
    if (r < 0 || r >= (int)g.size() || c < 0
        || c >= (int)g[0].size() || g[r][c] != '1')
        return;
    g[r][c] = '0';                     // mark visited
    sink(g, r + 1, c);
    sink(g, r - 1, c);
    sink(g, r, c + 1);
    sink(g, r, c - 1);
}

int countIslands(vector<string> g) {
    int islands = 0;
    for (int r = 0; r < (int)g.size(); r++)
        for (int c = 0; c < (int)g[0].size(); c++)
            if (g[r][c] == '1') {
                islands++;
                sink(g, r, c);
            }
    return islands;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "islands = "
         << countIslands({"11000", "11001", "00011", "00000", "10000"})
         << endl;
}
