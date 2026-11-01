// Fall in Love With DSA, Example 23.1: The backtracking template
// This is a fragment from the book, not a complete program.

void backtrack(State& state) {
    if (isComplete(state)) {
        record(state);
        return;
    }
    for (Choice c : choicesFor(state)) {
        if (!isValid(state, c)) continue;  // prune
        apply(state, c);                   // choose
        backtrack(state);                  // explore
        undo(state, c);                    // un-choose
    }
}
