// Fall in Love With DSA, Example 4.3: Elements are 4 bytes apart

#include <iostream>
using namespace std;

int main() {
    int arr[5] = {85, 90, 78, 92, 67};
    char* base = (char*)&arr[0];
    for (int i = 0; i < 5; i++) {
        long offset = (char*)&arr[i] - base;
        cout << "arr[" << i << "] is " << offset
             << " bytes from the start" << endl;
    }
    return 0;
}
