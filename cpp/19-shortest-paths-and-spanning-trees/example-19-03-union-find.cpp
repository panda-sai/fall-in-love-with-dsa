// Fall in Love With DSA, Example 19.3: Union-Find
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

// ---- code from the book ----
struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);   // compress
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;          // same group
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;  // small under big
        size[a] += size[b];
        return true;
    }
};

// ---- a small test, so you can run this example ----
int main() {
    DSU d(5);
    d.unite(0, 1);
    d.unite(1, 2);
    d.unite(3, 4);
    cout << "0 and 2 connected: " << (d.find(0) == d.find(2)) << endl;
    cout << "0 and 3 connected: " << (d.find(0) == d.find(3)) << endl;
}
