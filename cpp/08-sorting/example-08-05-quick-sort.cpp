// Fall in Love With DSA, Example 8.5: Quick sort
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
    int pivot = a[high];
    int i = low - 1;          // end of the smaller part
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);  // pivot to its place
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low >= high) return;
    int p = partition(a, low, high);
    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> a = {7, 2, 1, 8, 6, 3, 5, 4};
    quickSort(a, 0, a.size() - 1);
    for (int x : a) cout << x << " ";
    cout << endl;
}
