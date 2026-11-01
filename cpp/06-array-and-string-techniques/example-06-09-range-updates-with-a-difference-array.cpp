// Fall in Love With DSA, Example 6.9: Range updates with a difference array

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 6;
    vector<int> diff(n + 1, 0);
    int updates[3][3] = {{1, 3, 10}, {2, 5, 5},
                         {0, 0, 2}};
    for (auto& u : updates) {
        int l = u[0], r = u[1], v = u[2];
        diff[l] += v;
        diff[r + 1] -= v;
    }
    int running = 0;
    for (int i = 0; i < n; i++) {
        running += diff[i];
        cout << running << " ";
    }
    cout << endl;
    return 0;
}
