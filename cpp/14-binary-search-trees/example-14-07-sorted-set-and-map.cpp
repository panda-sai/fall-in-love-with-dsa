// Fall in Love With DSA, Example 14.7: Sorted set and map

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    set<int> s = {40, 10, 30, 20, 50};
    cout << "smallest = " << *s.begin()
         << ", largest = " << *s.rbegin() << endl;
    auto it = s.lower_bound(25);        // first >= 25
    cout << "first value >= 25 is " << *it << endl;
    s.erase(30);
    for (int x : s) cout << x << " ";   // sorted
    cout << endl;

    map<string, int> marks;
    marks["Ravi"] = 85;
    marks["Anil"] = 92;
    marks["Sita"] = 78;
    for (auto& [name, m] : marks)  // sorted by name
        cout << name << " " << m << endl;
    return 0;
}
