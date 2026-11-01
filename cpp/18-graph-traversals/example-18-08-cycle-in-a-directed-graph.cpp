// Fall in Love With DSA, Example 18.8: Cycle in a directed graph
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
// state: 0 = unvisited, 1 = on current path, 2 = done
bool hasDirectedCycle(const vector<vector<int>>& adj,
                      int u, vector<int>& state) {
    state[u] = 1;
    for (int v : adj[u]) {
        if (state[v] == 1) return true;  // back edge
        if (state[v] == 0
            && hasDirectedCycle(adj, v, state))
            return true;
    }
    state[u] = 2;
    return false;
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> s1(3, 0), s2(3, 0);
    cout << "0->1, 0->2, 2->1: "
         << hasDirectedCycle(directed(3, {{0, 1}, {0, 2}, {2, 1}}), 0,
                             s1)
         << endl;
    cout << "0->1, 1->2, 2->0: "
         << hasDirectedCycle(directed(3, {{0, 1}, {1, 2}, {2, 0}}), 0,
                             s2)
         << endl;
}
