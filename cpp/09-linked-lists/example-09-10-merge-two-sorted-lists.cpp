// Fall in Love With DSA, Example 9.10: Merge two sorted lists
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
Node* mergeLists(Node* a, Node* b) {
    Node dummy(0);
    Node* tail = &dummy;
    while (a != nullptr && b != nullptr) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a != nullptr) ? a : b;  // leftovers
    return dummy.next;
}

// ---- a small test, so you can run this example ----
int main() {
    printList(mergeLists(build({1, 3, 5}), build({2, 4, 6})));
}
