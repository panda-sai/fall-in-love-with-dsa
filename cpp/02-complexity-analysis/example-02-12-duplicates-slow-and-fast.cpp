// Fall in Love With DSA, Example 2.12: Duplicates, slow and fast

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Compare every pair: O(n²) time, O(1) space
bool hasDuplicateSlow(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return true;
        }
    }
    return false;
}

// Remember what we saw: O(n) time, O(n) space
bool hasDuplicateFast(const vector<int>& arr) {
    unordered_set<int> seen;
    for (int x : arr) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}

int main() {
    vector<int> a = {4, 9, 2, 7, 9};
    vector<int> b = {1, 2, 3, 4};
    cout << hasDuplicateSlow(a) << " "
         << hasDuplicateFast(a) << endl;
    cout << hasDuplicateSlow(b) << " "
         << hasDuplicateFast(b) << endl;
    return 0;
}
