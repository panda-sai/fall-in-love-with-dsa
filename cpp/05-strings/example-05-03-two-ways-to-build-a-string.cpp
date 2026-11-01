// Fall in Love With DSA, Example 5.3: Two ways to build a string
// This is a fragment from the book, not a complete program.

string s = "";
for (int i = 0; i < n; i++) {
    s += 'x';      // in place: amortised O(1)
}

string t = "";
for (int i = 0; i < n; i++) {
    t = t + 'x';   // a NEW string each time: O(i)
}
