// Fall in Love With DSA, Example 12.4: Two Sum with a hash map
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
vector<int> twoSum(const vector<int>& a, int target) {
    unordered_map<int, int> indexOf;  // value -> index
    for (int i = 0; i < (int)a.size(); i++) {
        int need = target - a[i];
        if (indexOf.count(need)) {
            return {indexOf[need], i};
        }
        indexOf[a[i]] = i;
    }
    return {};                           // no pair
}

// ---- a small test, so you can run this example ----
int main() {
    auto r = twoSum({2, 7, 11, 15}, 9);
    cout << "indexes " << r[0] << " and " << r[1] << endl;
    r = twoSum({3, 2, 4}, 6);
    cout << "indexes " << r[0] << " and " << r[1] << endl;
}
