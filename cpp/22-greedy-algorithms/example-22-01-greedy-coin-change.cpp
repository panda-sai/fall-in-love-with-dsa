// Fall in Love With DSA, Example 22.1: Greedy coin change
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
// coins sorted from largest to smallest
void greedyChange(const vector<int>& coins,
                  int amount) {
    int count = 0;
    for (int c : coins) {
        while (amount >= c) {
            cout << c << " ";
            amount -= c;
            count++;
        }
    }
    cout << "(" << count << " coins)" << endl;
}

// ---- a small test, so you can run this example ----
int main() {
    greedyChange({20, 10, 5, 2, 1}, 28);
    greedyChange({4, 3, 1}, 6);
}
