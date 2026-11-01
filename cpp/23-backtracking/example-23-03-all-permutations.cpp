// Fall in Love With DSA, Example 23.3: All permutations
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
void permute(const vector<int>& a, vector<bool>& used,
             vector<int>& current) {
    if (current.size() == a.size()) {
        for (int x : current) cout << x;
        cout << " ";
        return;
    }
    for (int i = 0; i < (int)a.size(); i++) {
        if (used[i]) continue;
        used[i] = true;                    // choose
        current.push_back(a[i]);
        permute(a, used, current);         // explore
        current.pop_back();                // undo
        used[i] = false;
    }
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> a = {1, 2, 3}, cur;
    vector<bool> used(3, false);
    permute(a, used, cur);
    cout << endl;
}
