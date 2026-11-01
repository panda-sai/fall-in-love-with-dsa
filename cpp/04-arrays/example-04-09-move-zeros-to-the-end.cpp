// Fall in Love With DSA, Example 4.9: Move zeros to the end

#include <iostream>
#include <vector>
using namespace std;

void moveZeros(vector<int>& arr) {
    int n = arr.size();
    int write = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[write] = arr[i];
            write++;
        }
    }
    while (write < n) {
        arr[write] = 0;
        write++;
    }
}

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZeros(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
