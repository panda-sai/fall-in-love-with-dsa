// Fall in Love With DSA, Example 5.6: Palindrome, ignoring case and symbols

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool isCleanPalindrome(const string& s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        if (!isalnum(s[left])) { left++; continue; }
        if (!isalnum(s[right])) { right--; continue; }
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    cout << isCleanPalindrome(
                "A man, a plan, a canal: Panama")
         << endl;
    cout << isCleanPalindrome("race a car") << endl;
    return 0;
}
