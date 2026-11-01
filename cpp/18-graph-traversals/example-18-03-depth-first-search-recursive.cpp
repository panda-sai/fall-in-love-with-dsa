// Fall in Love With DSA, Example 18.3: Depth-first search (recursive)
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
void dfs(const vector<vector<int>>& adj, int u,
         vector<bool>& visited) {
    visited[u] = true;
    cout << char('A' + u) << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, v, visited);
        }
    }
}

// ---- a small test, so you can run this example ----
int main() {
    auto g = sampleGraph();
    vector<bool> vis(7, false);
    dfs(g, 0, vis);
    cout << endl;
}
