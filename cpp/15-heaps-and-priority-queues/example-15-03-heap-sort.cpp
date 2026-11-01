// Fall in Love With DSA, Example 15.3: Heap sort
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
void siftDownMax(vector<int>& a, int i, int n) {
    while (true) {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) return;
        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDownMax(a, i, n);               // build
    for (int end = n - 1; end > 0; end--) {
        swap(a[0], a[end]);  // max to end
        siftDownMax(a, 0, end);  // fix the rest
    }
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> a = {12, 4, 19, 2, 8, 15, 1};
    heapSort(a);
    for (int x : a) cout << x << " ";
    cout << endl;
}
