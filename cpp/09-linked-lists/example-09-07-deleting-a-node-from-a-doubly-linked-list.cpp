// Fall in Love With DSA, Example 9.7: Deleting a node from a doubly linked list
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
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d)
        : data(d), prev(nullptr), next(nullptr) {}
};

// Removes node from the list; returns the (new) head.
DNode* removeNode(DNode* head, DNode* node) {
    if (node->prev) node->prev->next = node->next;
    else head = node->next;  // it was the head
    if (node->next) node->next->prev = node->prev;
    delete node;
    return head;
}

// ---- a small test, so you can run this example ----
int main() {
    DNode* a = new DNode(10);
    DNode* b = new DNode(20);
    DNode* c = new DNode(30);
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    DNode* h = removeNode(a, b);
    for (DNode* x = h; x; x = x->next) cout << x->data << " <-> ";
    cout << "null" << endl;
}
