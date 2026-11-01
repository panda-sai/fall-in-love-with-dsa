// Fall in Love With DSA, Example 18.2: Shortest distances with BFS
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
vector<int> bfsDistance(const vector<vector<int>>& adj,
                        int src) {
    vector<int> dist(adj.size(), -1);  // -1: unreached
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

// ---- a small test, so you can run this example ----
int main() {
    auto d = bfsDistance(sampleGraph(), 0);
    for (int i = 0; i < 7; i++)
        cout << char(65 + i) << ":" << d[i] << " ";
    cout << endl;
}
