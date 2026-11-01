// Fall in Love With DSA, Example 15.4: Using priority_queue

#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>>
        minHeap;
    for (int x : {12, 4, 19, 2, 8}) {
        maxHeap.push(x);
        minHeap.push(x);
    }
    cout << "max = " << maxHeap.top()
         << ", min = " << minHeap.top() << endl;

    // pairs compare by the first value, then the second
    priority_queue<pair<int, string>> tasks;
    tasks.push({2, "reply to email"});
    tasks.push({5, "fix the server"});
    tasks.push({1, "water the plants"});
    while (!tasks.empty()) {
        cout << tasks.top().second << endl;
        tasks.pop();
    }
    return 0;
}
