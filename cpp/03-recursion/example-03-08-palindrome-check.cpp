// Fall in Love With DSA, Example 3.8: Palindrome check

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int left,
                  int right) {
    if (left >= right) {
        return true;              // 0 or 1 characters
    }
    if (s[left] != s[right]) {
        return false;
    }
    return isPalindrome(s, left + 1, right - 1);
}

int main() {
    for (string s : {"madam", "level", "hello"}) {
        int n = s.size();
        bool ok = isPalindrome(s, 0, n - 1);
        cout << s << ": " << (ok ? "yes" : "no")
             << endl;
    }
    return 0;
}
