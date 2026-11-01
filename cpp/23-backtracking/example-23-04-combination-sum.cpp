// Fall in Love With DSA, Example 23.4: Combination sum
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
void combine(const vector<int>& nums, int start,
             int remaining, vector<int>& current) {
    if (remaining == 0) {
        cout << "{";
        for (int i = 0; i < (int)current.size(); i++)
            cout << (i ? ", " : "") << current[i];
        cout << "} ";
        return;
    }
    for (int i = start; i < (int)nums.size(); i++) {
        if (nums[i] > remaining) break;    // prune
        current.push_back(nums[i]);
        combine(nums, i, remaining - nums[i], current);
        current.pop_back();
    }
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> cur;
    combine({2, 3, 6, 7}, 0, 7, cur);
    cout << endl;
}
