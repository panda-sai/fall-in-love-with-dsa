// Fall in Love With DSA, Example 6.4: Remove duplicates in place

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;
    int write = 1;
    for (int read = 1; read < n; read++) {
        if (a[read] != a[write - 1]) {
            a[write] = a[read];
            write++;
        }
    }
    return write;
}

int main() {
    vector<int> a = {1, 1, 2, 2, 2, 3, 5, 5};
    int k = removeDuplicates(a);
    for (int i = 0; i < k; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
