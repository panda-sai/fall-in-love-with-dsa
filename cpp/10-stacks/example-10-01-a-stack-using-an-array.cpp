// Fall in Love With DSA, Example 10.1: A stack using an array
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
class ArrayStack {
    int arr[100];
    int top = -1;  // index of the top element
public:
    bool isEmpty() { return top == -1; }
    bool push(int x) {
        if (top == 99) return false;     // overflow
        arr[++top] = x;
        return true;
    }
    bool pop() {
        if (isEmpty()) return false;     // underflow
        top--;
        return true;
    }
    int peek() { return arr[top]; }  // if not empty
};

// ---- a small test, so you can run this example ----
int main() {
    ArrayStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "top = " << s.peek() << endl;
    s.pop();
    cout << "after pop, top = " << s.peek() << endl;
}
