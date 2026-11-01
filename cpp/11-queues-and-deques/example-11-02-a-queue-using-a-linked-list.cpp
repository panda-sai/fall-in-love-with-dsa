// Fall in Love With DSA, Example 11.2: A queue using a linked list
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
struct QNode {
    int data;
    QNode* next;
};

class ListQueue {
    QNode* head = nullptr;     // front
    QNode* tail = nullptr;     // rear
public:
    bool isEmpty() { return head == nullptr; }
    void enqueue(int x) {
        QNode* node = new QNode{x, nullptr};
        if (tail == nullptr) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    void dequeue() {
        if (isEmpty()) return;
        QNode* old = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete old;
    }
    int peek() { return head->data; }
};

// ---- a small test, so you can run this example ----
int main() {
    ListQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    cout << "front = " << q.peek() << endl;
}
