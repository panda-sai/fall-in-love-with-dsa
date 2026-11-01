// Fall in Love With DSA, Example 7.3: Recursive binary search
// This is a fragment from the book, not a complete program.

int search(const vector<int>& arr, int target,
           int left, int right) {
    if (left > right) {
        return -1;                  // empty range
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) {
        return search(arr, target, mid + 1, right);
    }
    return search(arr, target, left, mid - 1);
}
