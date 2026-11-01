// Fall in Love With DSA, Example 19.2: Bellman-Ford
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
struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};
vector<vector<pair<int, int>>> townGraph() {
    vector<vector<pair<int, int>>> adj(5);
    int e[6][3] = {{0, 1, 4}, {0, 2, 1}, {1, 2, 2},
                   {1, 3, 1}, {2, 3, 5}, {3, 4, 3}};
    for (auto& x : e) {
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }
    return adj;
}

// ---- code from the book ----
// edges: {from, to, weight}. Returns false if a
// negative cycle is reachable from src.
bool bellmanFord(int n,
                 const vector<array<int, 3>>& edges,
                 int src, vector<long long>& dist) {
    const long long INF = LLONG_MAX;
    dist.assign(n, INF);
    dist[src] = 0;
    for (int round = 1; round <= n - 1; round++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    for (auto [u, v, w] : edges) {           // round n
        if (dist[u] != INF && dist[u] + w < dist[v])
            return false;
    }
    return true;
}

// ---- a small test, so you can run this example ----
int main() {
    vector<long long> d;
    vector<array<int, 3>> e = {
        {0, 1, 2}, {0, 2, 5}, {1, 2, -4}, {2, 3, 3}};
    bellmanFord(4, e, 0, d);
    cout << "dist:";
    for (auto x : d) cout << " " << x;
    cout << endl;
    e.push_back({2, 1, 1});
    if (!bellmanFord(4, e, 0, d))
        cout << "negative cycle found" << endl;
}
