// Fall in Love With DSA, Example 3.2: Printing n to 1 with recursion

#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n == 0) {
        return;              // base case
    }
    cout << n << " ";
    printNumbers(n - 1);     // recursive case
}

int main() {
    printNumbers(5);
    cout << endl;
    return 0;
}
