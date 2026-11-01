// Fall in Love With DSA, Example 5.5: Anagram check by counting

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return false;
    }
    int count[26] = {};
    for (char c : a) count[c - 'a']++;
    for (char c : b) count[c - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isAnagram("listen", "silent") << endl;
    cout << isAnagram("rat", "car") << endl;
    return 0;
}
