// Fall in Love With DSA, Example 9.9: Detect a cycle
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
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// ---- a small test, so you can run this example ----
int main() {
    Node* h = build({1, 2, 3, 4, 5});
    cout << "without cycle: " << hasCycle(h) << endl;
    Node* last = h;
    while (last->next) last = last->next;
    last->next = h->next;
    cout << "with cycle: " << hasCycle(h) << endl;
}
