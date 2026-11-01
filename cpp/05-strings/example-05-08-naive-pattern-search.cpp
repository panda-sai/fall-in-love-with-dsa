// Fall in Love With DSA, Example 5.8: Naive pattern search

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> findAll(const string& text,
                    const string& pattern) {
    vector<int> positions;
    int n = text.size(), m = pattern.size();
    for (int i = 0; i + m <= n; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            positions.push_back(i);
        }
    }
    return positions;
}

int main() {
    for (int p : findAll("abracadabra", "abra")) {
        cout << p << " ";
    }
    cout << endl;
    return 0;
}
