// Fall in Love With DSA, Example 4.5: Insert and delete at a position

#include <iostream>
using namespace std;

// size = number of elements in use.
// The array must have room for size + 1 elements.
void insertAt(int arr[], int& size, int pos,
              int value) {
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];        // shift right
    }
    arr[pos] = value;
    size++;
}

void deleteAt(int arr[], int& size, int pos) {
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];        // shift left
    }
    size--;
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {10, 20, 30, 40};
    int size = 4;
    insertAt(arr, size, 1, 15);
    print(arr, size);
    deleteAt(arr, size, 3);
    print(arr, size);
    return 0;
}
