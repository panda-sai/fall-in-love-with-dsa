// Fall in Love With DSA, Example 12.1: Direct addressing

#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 5, 8, 21, 3, 17, 9};
    bool seen[100] = {};                 // all false
    for (int x : arr) {
        seen[x] = true;                  // build once
    }
    for (int q : {17, 4}) {  // each query O(1)
        cout << q << (seen[q] ? " is" : " is not")
             << " present" << endl;
    }
    return 0;
}
