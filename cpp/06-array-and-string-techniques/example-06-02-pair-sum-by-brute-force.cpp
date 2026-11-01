// Fall in Love With DSA, Example 6.2: Pair sum by brute force
// This is a fragment from the book, not a complete program.

for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        if (a[i] + a[j] == target)
            return true;
return false;
