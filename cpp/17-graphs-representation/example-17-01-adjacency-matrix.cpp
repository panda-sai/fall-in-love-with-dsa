// Fall in Love With DSA, Example 17.1: Adjacency matrix

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    int edges[5][2] = {{0, 1}, {0, 2}, {1, 2},
                       {1, 3}, {3, 4}};
    for (auto& e : edges) {
        adj[e[0]][e[1]] = 1;
        adj[e[1]][e[0]] = 1;        // undirected
    }
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++)
            cout << adj[u][v] << " ";
        cout << endl;
    }
    return 0;
}
