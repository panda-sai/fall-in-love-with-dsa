// Fall in Love With DSA, Example 10.2: A stack using a linked list
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
struct Node {
    int data;
    Node* next;
};

class ListStack {
    Node* head = nullptr;      // head is the top
public:
    bool isEmpty() { return head == nullptr; }
    void push(int x) {
        head = new Node{x, head};
    }
    void pop() {
        if (isEmpty()) return;
        Node* old = head;
        head = head->next;
        delete old;
    }
    int peek() { return head->data; }
};

// ---- a small test, so you can run this example ----
int main() {
    ListStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "top = " << s.peek() << endl;
    s.pop();
    cout << "after pop, top = " << s.peek() << endl;
}
