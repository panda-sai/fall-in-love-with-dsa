// Fall in Love With DSA, Example 10.4: Balanced brackets
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
bool isBalanced(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char open = st.top();
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "{[()]} : " << isBalanced("{[()]}") << endl;
    cout << "()[]{} : " << isBalanced("()[]{}") << endl;
    cout << "([)]   : " << isBalanced("([)]") << endl;
    cout << "((     : " << isBalanced("((") << endl;
}
