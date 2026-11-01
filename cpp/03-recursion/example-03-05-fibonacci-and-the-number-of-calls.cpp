// Fall in Love With DSA, Example 3.5: Fibonacci and the number of calls

#include <iostream>
using namespace std;

long long calls = 0;

long long fib(int n) {
    calls++;
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    for (int n : {10, 20, 30}) {
        calls = 0;
        long long answer = fib(n);
        cout << "fib(" << n << ") = " << answer
             << ", calls = " << calls << endl;
    }
    return 0;
}
