// Fall in Love With DSA, Example 4.4: Sum and average of marks

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> marks = {85, 90, 78, 92, 67};
    int n = marks.size();
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + marks[i];
    }
    double average = (double)sum / n;
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;
    return 0;
}
