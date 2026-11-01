// Fall in Love With DSA, Example 4.10: Rotate right by k

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void rotateRight(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;        // rotating by n changes nothing
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    rotateRight(arr, 3);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
