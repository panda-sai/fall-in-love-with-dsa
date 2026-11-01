// Fall in Love With DSA, Example 22.4: Minimum platforms
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// ---- code from the book ----
int minPlatforms(vector<int> arr, vector<int> dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0, j = 0, onStation = 0, best = 0;
    int n = arr.size();
    while (i < n) {
        if (arr[i] <= dep[j]) {      // a train arrives
            onStation++;
            i++;
            best = max(best, onStation);
        } else {                     // a train leaves
            onStation--;
            j++;
        }
    }
    return best;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << minPlatforms({900, 940, 950, 1100, 1500, 1800},
                         {910, 1200, 1120, 1130, 1900, 2000})
         << endl;
}
