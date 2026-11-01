// Fall in Love With DSA, Example 20.1: The bitwise operators

#include <bitset>
#include <iostream>
using namespace std;

int main() {
    int a = 12, b = 10;
    cout << bitset<4>(a) << " " << bitset<4>(b) << endl;
    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "~a    = " << (~a) << endl;
    cout << "a << 1 = " << (a << 1)
         << ", a >> 1 = " << (a >> 1) << endl;
    return 0;
}
