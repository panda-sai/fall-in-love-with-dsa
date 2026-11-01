// Fall in Love With DSA, Example 22.2: Activity selection
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
// each meeting is {start, end}
int maxMeetings(vector<pair<int, int>> m) {
    sort(m.begin(), m.end(),
         [](const auto& a, const auto& b) {
             return a.second < b.second;  // by end time
         });
    int count = 0, freeAt = -1;
    for (auto [s, e] : m) {
        if (s >= freeAt) {  // no overlap
            count++;
            freeAt = e;
            cout << "(" << s << ", " << e << ") ";
        }
    }
    cout << endl;
    return count;
}

// ---- a small test, so you can run this example ----
int main() {
    int c = maxMeetings({{1, 4},
                         {3, 5},
                         {0, 6},
                         {5, 7},
                         {3, 9},
                         {5, 9},
                         {6, 10},
                         {8, 11},
                         {8, 12},
                         {2, 14},
                         {12, 16}});
    cout << c << " meetings" << endl;
}
