// Fall in Love With DSA, Example 17.2: Adjacency list

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    int edges[5][2] = {{0, 1}, {0, 2}, {1, 2},
                       {1, 3}, {3, 4}};
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);  // undirected
    }
    for (int u = 0; u < n; u++) {
        cout << u << " (degree " << adj[u].size()
             << "):";
        for (int v : adj[u]) cout << " " << v;
        cout << endl;
    }
    return 0;
}
