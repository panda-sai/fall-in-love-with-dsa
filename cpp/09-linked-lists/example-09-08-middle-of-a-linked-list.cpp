// Fall in Love With DSA, Example 9.8: Middle of a linked list
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
Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// ---- a small test, so you can run this example ----
int main() {
    cout << "middle of 10 20 30 40 50 is "
         << middle(build({10, 20, 30, 40, 50}))->data << endl;
    cout << "middle of 10 20 30 40 is "
         << middle(build({10, 20, 30, 40}))->data << endl;
}
