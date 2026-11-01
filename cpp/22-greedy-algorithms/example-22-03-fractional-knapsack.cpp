// Fall in Love With DSA, Example 22.3: Fractional knapsack
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
// each item is {value, weight}
double fractionalKnapsack(vector<pair<int, int>> items,
                          int capacity) {
    sort(items.begin(), items.end(),
         [](const auto& a, const auto& b) {
             return (double)a.first / a.second
                  > (double)b.first / b.second;
         });
    double total = 0;
    for (auto [value, weight] : items) {
        if (capacity == 0) break;
        int take = min(weight, capacity);
        total += (double)value * take / weight;
        capacity -= take;
    }
    return total;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << fractionalKnapsack({{60, 10}, {100, 20}, {120, 30}}, 50)
         << endl;
}
