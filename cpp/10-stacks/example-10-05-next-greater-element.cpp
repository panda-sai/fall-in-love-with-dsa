// Fall in Love With DSA, Example 10.5: Next greater element
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
vector<int> nextGreater(const vector<int>& a) {
    int n = a.size();
    vector<int> answer(n, -1);
    stack<int> waiting;               // indexes
    for (int i = 0; i < n; i++) {
        while (!waiting.empty()
               && a[waiting.top()] < a[i]) {
            answer[waiting.top()] = a[i];
            waiting.pop();
        }
        waiting.push(i);
    }
    return answer;                    // left over: -1
}

// ---- a small test, so you can run this example ----
void show(vector<int> a) {
    for (int x : a) cout << x << " ";
    cout << "->";
    for (int x : nextGreater(a)) cout << " " << x;
    cout << endl;
}
int main() {
    show({4, 5, 2, 25});
    show({13, 7, 6, 12});
}
