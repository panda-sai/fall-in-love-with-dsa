// Fall in Love With DSA, Example 15.6: Merge k sorted arrays
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
vector<int> mergeK(const vector<vector<int>>& lists) {
    // {value, list index, position in that list}
    using Item = tuple<int, int, int>;
    priority_queue<Item, vector<Item>,
                   greater<Item>> pq;
    for (int i = 0; i < (int)lists.size(); i++)
        if (!lists[i].empty())
            pq.push({lists[i][0], i, 0});
    vector<int> result;
    while (!pq.empty()) {
        auto [value, i, pos] = pq.top();
        pq.pop();
        result.push_back(value);
        if (pos + 1 < (int)lists[i].size())
            pq.push({lists[i][pos + 1], i, pos + 1});
    }
    return result;
}

// ---- a small test, so you can run this example ----
int main() {
    for (int x : mergeK({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}))
        cout << x << " ";
    cout << endl;
}
