// Fall in Love With DSA, Example 3.9: Factorial with a loop
// This is a fragment from the book, not a complete program.

long long factorialLoop(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = result * i;
    }
    return result;
}
