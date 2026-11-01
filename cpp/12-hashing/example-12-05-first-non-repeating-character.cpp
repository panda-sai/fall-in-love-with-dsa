// Fall in Love With DSA, Example 12.5: First non-repeating character
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
char firstUnique(const string& s) {
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    for (char c : s) {
        if (count[c] == 1) return c;
    }
    return '-';                          // none
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "swiss: " << firstUnique("swiss") << endl;
    cout << "aabb: " << firstUnique("aabb") << endl;
}
