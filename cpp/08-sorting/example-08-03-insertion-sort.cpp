// Fall in Love With DSA, Example 8.3: Insertion sort
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
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];     // shift right
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---- a small test, so you can run this example ----
int main() {
    vector<int> a = {5, 3, 8, 1, 2};
    insertionSort(a);
    for (int x : a) cout << x << " ";
    cout << endl;
}
