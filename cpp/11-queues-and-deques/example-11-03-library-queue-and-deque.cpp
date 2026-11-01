// Fall in Love With DSA, Example 11.3: Library queue and deque

#include <deque>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10); q.push(20); q.push(30);
    q.pop();                              // removes 10
    cout << "queue front = " << q.front()
         << ", back = " << q.back() << endl;

    deque<int> d;
    d.push_back(20);
    d.push_back(30);
    d.push_front(10);                     // 10 20 30
    d.pop_back();                         // 10 20
    cout << "deque front = " << d.front()
         << ", back = " << d.back() << endl;
    return 0;
}
