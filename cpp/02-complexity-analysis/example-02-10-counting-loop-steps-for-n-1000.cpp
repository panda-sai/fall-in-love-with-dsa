// Fall in Love With DSA, Example 2.10: Counting loop steps for n = 1000

#include <iostream>
using namespace std;

int main() {
    int n = 1000;
    long long halving = 0, square = 0, fixed5 = 0;
    long long triangle = 0, doubling = 0;

    for (int x = n; x > 1; x = x / 2) halving++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) square++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++) fixed5++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) triangle++;
    for (int i = 1; i < n; i = i * 2) doubling++;

    cout << "halving  : " << halving << endl;
    cout << "n x n    : " << square << endl;
    cout << "n x 5    : " << fixed5 << endl;
    cout << "triangle : " << triangle << endl;
    cout << "doubling : " << doubling << endl;
    return 0;
}
