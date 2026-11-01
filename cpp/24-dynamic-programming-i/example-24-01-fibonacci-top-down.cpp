// Fall in Love With DSA, Example 24.1: Fibonacci, top-down
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
vector<long long> memo(91, -1);

long long fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];        // reuse
    return memo[n] = fib(n - 1) + fib(n - 2); // store
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "fib(50) = " << fib(50) << endl;
    cout << "fib(90) = " << fib(90) << endl;
}
