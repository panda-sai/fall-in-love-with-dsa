// Fall in Love With DSA, Example 5.7: Reverse the words of a sentence

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string reverseWords(const string& s) {
    istringstream in(s);
    vector<string> words;
    string word;
    while (in >> word) {        // skips extra spaces
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    string result;
    for (int i = 0; i < (int)words.size(); i++) {
        if (i > 0) result += ' ';
        result += words[i];
    }
    return result;
}

int main() {
    cout << reverseWords("the sky is blue") << endl;
    cout << reverseWords("  hello   world ") << endl;
    return 0;
}
