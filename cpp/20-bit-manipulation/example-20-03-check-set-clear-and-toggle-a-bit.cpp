// Fall in Love With DSA, Example 20.3: Check, set, clear and toggle a bit
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
bool checkBit(int n, int k)  { return (n >> k) & 1; }
int setBit(int n, int k)     { return n | (1 << k); }
int clearBit(int n, int k)   { return n & ~(1 << k); }
int toggleBit(int n, int k)  { return n ^ (1 << k); }

// ---- a small test, so you can run this example ----
int main() {
    int n = 12;
    cout << "12 = 1100" << endl;
    cout << "check bit 2: " << checkBit(n, 2) << endl;
    cout << "set bit 0: " << setBit(n, 0) << " (1101)" << endl;
    cout << "clear bit 3: " << clearBit(n, 3) << " (0100)" << endl;
    cout << "toggle bit 1: " << toggleBit(n, 1) << " (1110)" << endl;
}
