// Fall in Love With DSA, Example 10.3: Using std::stack

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "top = " << st.top() << endl;
    st.pop();
    cout << "after pop, top = " << st.top() << endl;
    cout << "size = " << st.size() << endl;
    return 0;
}
