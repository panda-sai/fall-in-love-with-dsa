// Fall in Love With DSA, Example 12.6: Count subarrays with sum k
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
int countSubarrays(const vector<int>& a, int k) {
    unordered_map<long long, int> prefixCount;
    prefixCount[0] = 1;                  // empty prefix
    long long prefix = 0;
    int count = 0;
    for (int x : a) {
        prefix += x;
        if (prefixCount.count(prefix - k))
            count += prefixCount[prefix - k];
        prefixCount[prefix]++;
    }
    return count;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "{1, 2, 3}, k = 3: " << countSubarrays({1, 2, 3}, 3)
         << endl;
    cout << "{1, -1, 0}, k = 0: " << countSubarrays({1, -1, 0}, 0)
         << endl;
}
