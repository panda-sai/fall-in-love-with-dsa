// Fall in Love With DSA, Example 2.13: How a vector grows

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    size_t lastCapacity = 0;
    for (int i = 1; i <= 100; i++) {
        v.push_back(i);
        if (v.capacity() != lastCapacity) {
            lastCapacity = v.capacity();
            cout << "size " << v.size()
                 << " -> capacity " << lastCapacity
                 << endl;
        }
    }
    return 0;
}
