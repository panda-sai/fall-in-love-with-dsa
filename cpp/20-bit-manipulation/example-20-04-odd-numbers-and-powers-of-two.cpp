// Fall in Love With DSA, Example 20.4: Odd numbers and powers of two
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
bool isOdd(int n) { return n & 1; }

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "7 odd: " << isOdd(7) << ", 10 odd: " << isOdd(10) << endl;
    cout << "16 power of two: " << isPowerOfTwo(16)
         << ", 12 power of two: " << isPowerOfTwo(12) << endl;
}
