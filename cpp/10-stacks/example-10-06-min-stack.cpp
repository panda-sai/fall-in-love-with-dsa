// Fall in Love With DSA, Example 10.6: Min stack
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
class MinStack {
    stack<int> values, mins;
public:
    void push(int x) {
        values.push(x);
        if (mins.empty() || x <= mins.top())
            mins.push(x);
        else mins.push(mins.top());
    }
    void pop() { values.pop(); mins.pop(); }
    int top() { return values.top(); }
    int getMin() { return mins.top(); }
};

// ---- a small test, so you can run this example ----
int main() {
    MinStack m;
    for (int x : {5, 3, 7, 2}) m.push(x);
    cout << "min = " << m.getMin() << endl;
    m.pop();
    cout << "after pop, min = " << m.getMin() << endl;
}
