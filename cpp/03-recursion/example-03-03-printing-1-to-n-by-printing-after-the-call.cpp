// Fall in Love With DSA, Example 3.3: Printing 1 to n by printing after the call

#include <iostream>
using namespace std;

void printUp(int n) {
    if (n == 0) {
        return;
    }
    printUp(n - 1);          // first print 1 to n-1
    cout << n << " ";        // then print n
}

int main() {
    printUp(5);
    cout << endl;
    return 0;
}
