// Fall in Love With DSA, Example 19.1: Dijkstra's algorithm
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
// adj[u] = list of {v, weight}
vector<long long> dijkstra(
        const vector<vector<pair<int, int>>>& adj,
        int src, vector<int>& parent) {
    int n = adj.size();
    vector<long long> dist(n, LLONG_MAX);
    parent.assign(n, -1);
    using Item = pair<long long, int>;      // {dist, v}
    priority_queue<Item, vector<Item>,
                   greater<Item>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;  // out of date
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {     // relax
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> parent;
    auto d = dijkstra(townGraph(), 0, parent);
    cout << "dist:";
    for (auto x : d) cout << " " << x;
    cout << endl;
    vector<int> path;
    for (int v = 4; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "path to 4:";
    for (int v : path) cout << " " << v;
    cout << endl;
}
