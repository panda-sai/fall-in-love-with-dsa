// Fall in Love With DSA, Example 1.1: Sum of first n numbers using a loop

#include <iostream>
using namespace std;

int main() {
    int n = 10;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}
