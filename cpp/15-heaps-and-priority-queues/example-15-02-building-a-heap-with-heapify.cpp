// Fall in Love With DSA, Example 15.2: Building a heap with heapify
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
void siftDown(vector<int>& h, int i, int n) {
    while (true) {
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && h[l] < h[smallest]) smallest = l;
        if (r < n && h[r] < h[smallest]) smallest = r;
        if (smallest == i) return;
        swap(h[i], h[smallest]);
        i = smallest;
    }
}

void buildHeap(vector<int>& h) {
    int n = h.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftDown(h, i, n);
    }
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> h = {12, 4, 19, 2, 8, 15, 1};
    buildHeap(h);
    for (int x : h) cout << x << " ";
    cout << endl;
}
