// Fall in Love With DSA, Example 2.11: Sequential loops
// This is a fragment from the book, not a complete program.

for (int i = 0; i < n; i++) {          // n steps
    cout << i << endl;
}
for (int i = 0; i < n; i++) {          // n × n steps
    for (int j = 0; j < n; j++) {
        cout << i + j << endl;
    }
}
