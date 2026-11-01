// Fall in Love With DSA, Example 11.1: A circular queue
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
class CircularQueue {
    vector<int> arr;
    int front = 0, count = 0, capacity;
public:
    CircularQueue(int cap) : arr(cap), capacity(cap) {}
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == capacity; }
    bool enqueue(int x) {
        if (isFull()) return false;
        int rear = (front + count) % capacity;
        arr[rear] = x;
        count++;
        return true;
    }
    bool dequeue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    int peek() { return arr[front]; }
};

// ---- a small test, so you can run this example ----
int main() {
    CircularQueue q(5);
    for (int x : {10, 20, 30, 40, 50}) q.enqueue(x);
    q.dequeue();
    q.dequeue();
    q.enqueue(60);
    q.enqueue(70);
    cout << "front = " << q.peek() << ", full = " << q.isFull() << endl;
    cout << "queue:";
    while (!q.isEmpty()) {
        cout << " " << q.peek();
        q.dequeue();
    }
    cout << endl;
}
