// Fall in Love With DSA, Example 7.8: Minimum reading speed

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool canFinish(const vector<int>& pages, int s, int H) {
    long long hours = 0;
    for (int p : pages) {
        hours += (p + s - 1) / s;   // p / s, rounded up
    }
    return hours <= H;
}

int minSpeed(const vector<int>& pages, int H) {
    int left = 1;
    int right = *max_element(pages.begin(),
                             pages.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canFinish(pages, mid, H)) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    cout << minSpeed({3, 6, 7, 11}, 8) << endl;
    cout << minSpeed({30, 11, 23, 4, 20}, 5) << endl;
    cout << minSpeed({30, 11, 23, 4, 20}, 6) << endl;
    return 0;
}
