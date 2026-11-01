// Fall in Love With DSA, Example 9.6: Reverse a linked list
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

// ---- helpers used by the test below (not printed in the book) ----
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {
    }
};
void printList(Node* head) {
    for (Node* c = head; c; c = c->next) cout << c->data << " -> ";
    cout << "null" << endl;
}
Node* build(vector<int> v) {
    Node dummy(0);
    Node* t = &dummy;
    for (int x : v) {
        t->next = new Node(x);
        t = t->next;
    }
    return dummy.next;
}

// ---- code from the book ----
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;   // save the rest
        curr->next = prev;  // turn the arrow back
        prev = curr;               // move both forward
        curr = next;
    }
    return prev;                   // the new head
}

// ---- a small test, so you can run this example ----
int main() {
    printList(reverseList(build({10, 20, 30})));
}
