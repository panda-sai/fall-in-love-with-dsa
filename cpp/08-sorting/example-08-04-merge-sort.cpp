// Fall in Love With DSA, Example 8.4: Merge sort
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
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> out;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) out.push_back(a[i++]);
        else out.push_back(a[j++]);
    }
    while (i <= m) out.push_back(a[i++]);
    while (j <= r) out.push_back(a[j++]);
    for (int k = 0; k < (int)out.size(); k++) {
        a[l + k] = out[k];
    }
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;              // 0 or 1 element
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> a = {8, 3, 7, 4, 9, 2, 6, 5};
    mergeSort(a, 0, a.size() - 1);
    for (int x : a) cout << x << " ";
    cout << endl;
}
