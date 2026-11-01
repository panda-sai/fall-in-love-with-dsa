// Fall in Love With DSA, Example 6.8: Range sum queries with prefix sums

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2};
    int n = arr.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    int queries[3][2] = {{1, 3}, {0, 6}, {4, 5}};
    for (auto& q : queries) {
        int l = q[0], r = q[1];
        cout << "sum(" << l << ", " << r << ") = "
             << prefix[r + 1] - prefix[l] << endl;
    }
    return 0;
}
