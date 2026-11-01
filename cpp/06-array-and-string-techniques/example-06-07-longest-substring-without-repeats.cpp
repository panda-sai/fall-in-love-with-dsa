// Fall in Love With DSA, Example 6.7: Longest substring without repeats

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int longestUnique(const string& s) {
    int count[256] = {};
    int n = s.size(), left = 0, best = 0;
    for (int right = 0; right < n; right++) {
        unsigned char c = s[right];
        count[c]++;
        while (count[c] > 1) {       // c is repeated
            count[(unsigned char)s[left]]--;
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    cout << longestUnique("abcabcbb") << endl;
    cout << longestUnique("pwwkew") << endl;
    cout << longestUnique("bbbbb") << endl;
    return 0;
}
