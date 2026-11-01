// Fall in Love With DSA, Example 10.7: Evaluate a postfix expression
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
int evalPostfix(const vector<string>& tokens) {
    stack<int> st;
    for (const string& t : tokens) {
        bool isOp = t == "+" || t == "-"
                    || t == "*" || t == "/";
        if (isOp) {
            int right = st.top(); st.pop();
            int left = st.top(); st.pop();
            if (t == "+") st.push(left + right);
            if (t == "-") st.push(left - right);
            if (t == "*") st.push(left * right);
            if (t == "/") st.push(left / right);
        } else {
            st.push(stoi(t));         // string to int
        }
    }
    return st.top();
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "3 4 2 * + = " << evalPostfix({"3", "4", "2", "*", "+"})
         << endl;
}
