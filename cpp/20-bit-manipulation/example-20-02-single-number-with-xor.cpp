// Fall in Love With DSA, Example 20.2: Single number with XOR
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
int singleNumber(const vector<int>& a) {
    int result = 0;
    for (int x : a) result ^= x;
    return result;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << singleNumber({4, 2, 7, 2, 4}) << endl;
}
