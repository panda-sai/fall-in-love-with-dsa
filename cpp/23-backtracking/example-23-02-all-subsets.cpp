// Fall in Love With DSA, Example 23.2: All subsets
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
void subsets(const vector<int>& a, int i,
             vector<int>& current) {
    if (i == (int)a.size()) {  // decided all
        cout << "{";
        for (int x : current) cout << x;
        cout << "} ";
        return;
    }
    subsets(a, i + 1, current);  // leave a[i] out
    current.push_back(a[i]);               // take a[i]
    subsets(a, i + 1, current);
    current.pop_back();                    // undo
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> cur;
    subsets({1, 2, 3}, 0, cur);
    cout << endl;
}
