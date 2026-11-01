// Fall in Love With DSA, Example 6.3: Pair sum with two pointers

#include <iostream>
#include <vector>
using namespace std;

bool hasPair(const vector<int>& a, int target) {
    int left = 0, right = (int)a.size() - 1;
    while (left < right) {
        int sum = a[left] + a[right];
        if (sum == target) {
            cout << a[left] << " + " << a[right]
                 << " = " << target << endl;
            return true;
        }
        if (sum < target) left++;
        else right--;
    }
    return false;
}

int main() {
    vector<int> a = {1, 3, 4, 6, 8, 11};
    hasPair(a, 10);
    cout << hasPair(a, 20) << endl;
    return 0;
}
