// Fall in Love With DSA, Example 21.3: Quickselect
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
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (a[j] < pivot) swap(a[++i], a[j]);
    swap(a[i + 1], a[high]);
    return i + 1;
}

// k-th smallest, k counted from 1
int quickSelect(vector<int> a, int k) {
    int low = 0, high = a.size() - 1, target = k - 1;
    while (true) {
        int p = partition(a, low, high);
        if (p == target) return a[p];
        if (target < p) high = p - 1;
        else low = p + 1;
    }
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "3rd smallest of {7, 10, 4, 3, 20, 15} is "
         << quickSelect({7, 10, 4, 3, 20, 15}, 3) << endl;
}
