// Fall in Love With DSA, Example 5.4: Counting letters

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "banana";
    int count[26] = {};             // all zeros
    for (char c : s) {
        count[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            cout << char('a' + i) << ": "
                 << count[i] << endl;
        }
    }
    return 0;
}
