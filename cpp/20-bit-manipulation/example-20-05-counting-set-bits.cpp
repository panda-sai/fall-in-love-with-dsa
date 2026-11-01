// Fall in Love With DSA, Example 20.5: Counting set bits
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
int countBitsSimple(unsigned n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int countBitsKernighan(unsigned n) {
    int count = 0;
    while (n > 0) {
        n &= n - 1;  // remove the lowest set bit
        count++;
    }
    return count;
}

// ---- a small test, so you can run this example ----
int main() {
    for (unsigned x : {12u, 255u})
        cout << x << ": " << countBitsSimple(x) << " "
             << countBitsKernighan(x) << endl;
}
