// Fall in Love With DSA, Example 3.7: Fast power

#include <iostream>
using namespace std;

long long power(long long x, int n) {
    if (n == 0) {
        return 1;
    }
    long long half = power(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    }
    return half * half * x;
}

int main() {
    cout << power(2, 10) << endl;
    cout << power(3, 13) << endl;
    return 0;
}
