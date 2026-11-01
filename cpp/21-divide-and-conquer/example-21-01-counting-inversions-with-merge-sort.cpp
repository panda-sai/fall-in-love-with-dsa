// Fall in Love With DSA, Example 21.1: Counting inversions with merge sort
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
long long sortCount(vector<int>& a, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    long long count = sortCount(a, l, m)
                    + sortCount(a, m + 1, r);
    vector<int> out;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            out.push_back(a[i++]);
        } else {
            count += m - i + 1;  // a[j] < a[i..m]
            out.push_back(a[j++]);
        }
    }
    while (i <= m) out.push_back(a[i++]);
    while (j <= r) out.push_back(a[j++]);
    for (int k = 0; k < (int)out.size(); k++)
        a[l + k] = out[k];
    return count;
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> a = {2, 4, 1, 3, 5}, b = {8, 4, 2, 1};
    cout << "{2, 4, 1, 3, 5}: " << sortCount(a, 0, 4) << endl;
    cout << "{8, 4, 2, 1}: " << sortCount(b, 0, 3) << endl;
}
