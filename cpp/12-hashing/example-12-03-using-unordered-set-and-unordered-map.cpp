// Fall in Love With DSA, Example 12.3: Using unordered_set and unordered_map

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    // set: check for a duplicate
    unordered_set<int> seen;
    for (int x : {4, 9, 2, 7, 9, 1}) {
        if (seen.count(x)) {
            cout << "duplicate: " << x << endl;
            break;
        }
        seen.insert(x);
    }

    // map: count word frequencies
    unordered_map<string, int> freq;
    for (string w : {"to", "be", "or", "not",
                     "to", "be"})
        freq[w]++;
    cout << "to: " << freq["to"] << ", or: "
         << freq["or"] << endl;
    return 0;
}
