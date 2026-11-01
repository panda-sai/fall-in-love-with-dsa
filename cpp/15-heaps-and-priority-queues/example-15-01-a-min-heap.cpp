// Fall in Love With DSA, Example 15.1: A min-heap
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
class MinHeap {
    vector<int> h;
    void siftUp(int i) {
        while (i > 0 && h[i] < h[(i - 1) / 2]) {
            swap(h[i], h[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void siftDown(int i) {
        int n = h.size();
        while (true) {
            int smallest = i;
            int l = 2 * i + 1, r = 2 * i + 2;
            if (l < n && h[l] < h[smallest])
                smallest = l;
            if (r < n && h[r] < h[smallest])
                smallest = r;
            if (smallest == i) return;  // order is fine
            swap(h[i], h[smallest]);
            i = smallest;
        }
    }
public:
    bool empty() { return h.empty(); }
    int top() { return h[0]; }
    void push(int x) {
        h.push_back(x);
        siftUp(h.size() - 1);
    }
    void pop() {
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) siftDown(0);
    }
};

// ---- a small test, so you can run this example ----
int main() {
    MinHeap h;
    for (int x : {12, 4, 19, 2, 8, 15, 1}) h.push(x);
    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;
}
