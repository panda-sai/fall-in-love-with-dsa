// Fall in Love With DSA, Example 4.6: Common vector operations

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    v.push_back(40);                  // add at end
    v.insert(v.begin() + 1, 15);      // add at index 1
    v.erase(v.begin() + 2);           // remove index 2
    v.pop_back();                     // remove last
    cout << "size = " << v.size()
         << ", front = " << v.front()
         << ", back = " << v.back() << endl;
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
