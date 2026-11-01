// Fall in Love With DSA, Example 3.4: Factorial

#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1) {
        return 1;                        // 0! = 1! = 1
    }
    return n * factorial(n - 1);
}

int main() {
    cout << factorial(5) << endl;
    cout << factorial(20) << endl;
    return 0;
}
