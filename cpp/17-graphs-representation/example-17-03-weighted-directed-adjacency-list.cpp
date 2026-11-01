// Fall in Love With DSA, Example 17.3: Weighted directed adjacency list

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;
    vector<vector<pair<int, int>>> adj(n);  // {to, w}
    adj[0].push_back({1, 4});      // 0 -> 1, weight 4
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 5});
    for (int u = 0; u < n; u++) {
        for (auto [v, w] : adj[u])
            cout << u << " -> " << v << " (" << w << ")"
                 << endl;
    }
    return 0;
}
