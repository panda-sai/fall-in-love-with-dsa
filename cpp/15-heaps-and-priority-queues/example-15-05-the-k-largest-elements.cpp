// Fall in Love With DSA, Example 15.5: The k largest elements
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
vector<int> topK(const vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> club;
    for (int x : a) {
        if ((int)club.size() < k) {
            club.push(x);
        } else if (x > club.top()) {
            club.pop();
            club.push(x);
        }
    }
    vector<int> result;
    while (!club.empty()) {
        result.push_back(club.top());
        club.pop();
    }
    return result;  // in increasing order
}

// ---- a small test, so you can run this example ----
int main() {
    for (int x : topK({12, 4, 19, 2, 8, 15, 1}, 3)) cout << x << " ";
    cout << endl;
}
