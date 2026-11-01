// Fall in Love With DSA, Example 5.2: Character arithmetic

#include <cctype>
#include <iostream>
using namespace std;

int main() {
    char c = 'C';
    cout << int(c) << endl;             // its code
    cout << c - 'A' << endl;            // position
    char d = '7';
    cout << d - '0' << endl;            // digit value
    cout << char('a' + 4) << endl;      // 5th letter
    cout << char(toupper('m')) << endl;
    return 0;
}
