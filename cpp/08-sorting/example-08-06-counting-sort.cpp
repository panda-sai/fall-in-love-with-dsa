// Fall in Love With DSA, Example 8.6: Counting sort
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
void countingSort(vector<int>& a, int maxValue) {
    vector<int> count(maxValue + 1, 0);
    for (int x : a) {
        count[x]++;
    }
    int idx = 0;
    for (int v = 0; v <= maxValue; v++) {
        for (int c = 0; c < count[v]; c++) {
            a[idx++] = v;
        }
    }
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> a = {4, 2, 2, 8, 3, 3, 1};
    countingSort(a, 8);
    for (int x : a) cout << x << " ";
    cout << endl;
}
