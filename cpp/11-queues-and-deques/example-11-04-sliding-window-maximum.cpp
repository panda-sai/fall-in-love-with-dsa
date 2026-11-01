// Fall in Love With DSA, Example 11.4: Sliding window maximum
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
vector<int> windowMax(const vector<int>& a, int k) {
    deque<int> dq;                     // indexes
    vector<int> result;
    for (int i = 0; i < (int)a.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();            // out of window
        while (!dq.empty() && a[dq.back()] < a[i])
            dq.pop_back();  // never useful again
        dq.push_back(i);
        if (i >= k - 1)
            result.push_back(a[dq.front()]);
    }
    return result;
}

// ---- a small test, so you can run this example ----
int main() {
    for (int x : windowMax({1, 3, -1, -3, 5, 3, 6, 7}, 3))
        cout << x << " ";
    cout << endl;
}
