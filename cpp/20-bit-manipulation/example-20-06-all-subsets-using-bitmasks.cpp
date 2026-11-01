// Fall in Love With DSA, Example 20.6: All subsets using bitmasks

#include <iostream>
#include <string>
using namespace std;

int main() {
    string items = "abc";
    int n = items.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "{";
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) cout << items[i];
        cout << "} ";
    }
    cout << endl;
    return 0;
}
