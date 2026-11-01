// Fall in Love With DSA, Example 9.5: Delete by value
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
Node* deleteValue(Node* head, int value) {
    if (head == nullptr) return nullptr;
    if (head->data == value) {           // delete head
        Node* rest = head->next;
        delete head;
        return rest;
    }
    Node* prev = head;
    while (prev->next != nullptr
           && prev->next->data != value) {
        prev = prev->next;
    }
    if (prev->next != nullptr) {         // found it
        Node* target = prev->next;
        prev->next = target->next;       // skip over it
        delete target;
    }
    return head;
}

// ---- a small test, so you can run this example ----
int main() {
    Node* h = build({10, 20, 30, 40});
    h = deleteValue(h, 20);
    printList(h);
}
