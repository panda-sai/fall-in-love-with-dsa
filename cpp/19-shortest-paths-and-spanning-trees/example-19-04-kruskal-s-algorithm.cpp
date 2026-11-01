// Fall in Love With DSA, Example 19.4: Kruskal's algorithm
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
// edges: {weight, u, v}
long long kruskal(int n, vector<array<int, 3>> edges) {
    sort(edges.begin(), edges.end());       // by weight
    DSU dsu(n);
    long long total = 0;
    int used = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {              // no cycle
            total += w;
            cout << u << "-" << v << " (" << w << ")\n";
            if (++used == n - 1) break;
        }
    }
    return total;
}

// ---- a small test, so you can run this example ----
int main() {
    long long t = kruskal(5, {{4, 0, 1},
                              {1, 0, 2},
                              {2, 1, 2},
                              {1, 1, 3},
                              {5, 2, 3},
                              {3, 3, 4}});
    cout << "total = " << t << endl;
}
