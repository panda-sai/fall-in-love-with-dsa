// Fall in Love With DSA, Example 12.2: A hash set with chaining
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
class HashSet {
    vector<list<int>> buckets;
    int m;
    int h(int key) { return ((key % m) + m) % m; }
public:
    HashSet(int size) : buckets(size), m(size) {}
    bool contains(int key) {
        for (int x : buckets[h(key)])
            if (x == key) return true;
        return false;
    }
    void insert(int key) {
        if (!contains(key))
            buckets[h(key)].push_back(key);
    }
    void remove(int key) {
        buckets[h(key)].remove(key);
    }
};

// ---- a small test, so you can run this example ----
int main() {
    HashSet s(10);
    for (int x : {12, 5, 8, 21, 3, 17, 9, 22}) s.insert(x);
    cout << "contains 17: " << s.contains(17) << endl;
    cout << "contains 7: " << s.contains(7) << endl;
    s.remove(17);
    cout << "after removing 17: " << s.contains(17) << endl;
}
