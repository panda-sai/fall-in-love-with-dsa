// Fall in Love With DSA, Example 1.3: Highest marks in a class

#include <iostream>
#include <vector>
using namespace std;

int findHighest(const vector<int>& marks) {
    int highest = marks[0];
    int n = marks.size();
    for (int i = 1; i < n; i++) {
        if (marks[i] > highest) {
            highest = marks[i];
        }
    }
    return highest;
}

int main() {
    vector<int> marks = {67, 82, 45, 91, 78};
    cout << "Highest = " << findHighest(marks) << endl;
    return 0;
}
