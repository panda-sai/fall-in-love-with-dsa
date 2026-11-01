// Fall in Love With DSA, Example 7.7: Integer square root

#include <iostream>
using namespace std;

long long intSqrt(long long n) {
    long long left = 0, right = n, answer = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid * mid <= n) {
            answer = mid;  // mid works; try bigger
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    cout << intSqrt(26) << endl;
    cout << intSqrt(1000000) << endl;
    return 0;
}
