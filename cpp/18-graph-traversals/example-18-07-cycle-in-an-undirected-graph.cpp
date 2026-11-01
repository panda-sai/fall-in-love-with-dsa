// Fall in Love With DSA, Example 18.7: Cycle in an undirected graph
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
bool hasCycle(const vector<vector<int>>& adj, int u,
              int parent, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycle(adj, v, u, visited))
                return true;
        } else if (v != parent) {
            return true;  // visited, not parent
        }
    }
    return false;
}

// ---- a small test, so you can run this example ----
int main() {
    vector<bool> v1(7, false), v2(7, false);
    cout << "our graph: " << hasCycle(sampleGraph(), 0, -1, v1) << endl;
    auto g =
        undirected(7, {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {4, 6}});
    cout << "our graph without F-G: " << hasCycle(g, 0, -1, v2) << endl;
}
