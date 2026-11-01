// Fall in Love With DSA, Example 24.6: Kadane's algorithm
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
long long maxSubarray(const vector<int>& a) {
    long long endingHere = a[0], best = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        endingHere = max((long long)a[i],
                         endingHere + a[i]);
        best = max(best, endingHere);
    }
    return best;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << maxSubarray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
}
