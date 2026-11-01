// Fall in Love With DSA, Example 6.1: Reverse an array in place

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& a) {
    int left = 0, right = (int)a.size() - 1;
    while (left < right) {
        swap(a[left], a[right]);
        left++;
        right--;
    }
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    reverseArray(a);
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
