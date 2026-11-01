// Fall in Love With DSA, Example 3.6: Fibonacci with memoisation

#include <iostream>
#include <vector>
using namespace std;

long long calls = 0;

long long fibMemo(int n, vector<long long>& memo) {
    calls++;
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];         // already computed
    }
    memo[n] = fibMemo(n - 1, memo)
            + fibMemo(n - 2, memo);
    return memo[n];
}

int main() {
    for (int n : {30, 90}) {
        vector<long long> memo(n + 1, -1);
        calls = 0;
        long long answer = fibMemo(n, memo);
        cout << "fib(" << n << ") = " << answer
             << ", calls = " << calls << endl;
    }
    return 0;
}
