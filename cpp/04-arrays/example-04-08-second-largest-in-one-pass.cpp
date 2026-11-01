// Fall in Love With DSA, Example 4.8: Second largest in one pass

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int secondLargest(const vector<int>& arr) {
    int first = INT_MIN, second = INT_MIN;
    for (int x : arr) {
        if (x > first) {
            second = first;
            first = x;
        } else if (x < first && x > second) {
            second = x;
        }
    }
    return second;   // INT_MIN if it does not exist
}

int main() {
    cout << secondLargest({12, 35, 1, 10, 34, 1})
         << endl;
    cout << secondLargest({10, 10, 8}) << endl;
    return 0;
}
