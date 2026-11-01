// Fall in Love With DSA, Example 23.5: N-Queens
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// ---- code from the book ----
int n, solutions = 0;
vector<bool> col, diag1, diag2;    // see the text
vector<string> board;

void place(int r) {
    if (r == n) {
        if (solutions == 0)  // print the first
            for (auto& row : board) cout << row << endl;
        solutions++;
        return;
    }
    for (int c = 0; c < n; c++) {
        int d1 = r - c + n - 1, d2 = r + c;
        if (col[c] || diag1[d1] || diag2[d2])
            continue;                      // attacked
        col[c] = diag1[d1] = diag2[d2] = true;
        board[r][c] = 'Q';
        place(r + 1);
        board[r][c] = '.';                 // undo
        col[c] = diag1[d1] = diag2[d2] = false;
    }
}

// ---- a small test, so you can run this example ----
void solve(int size, bool show) {
    n = size;
    solutions = show ? 0 : 1;
    col.assign(n, false);
    diag1.assign(2 * n, false);
    diag2.assign(2 * n, false);
    board.assign(n, string(n, '.'));
    place(0);
    cout << "n = " << n << ": " << (show ? solutions : solutions - 1)
         << " solutions" << endl;
}
int main() {
    solve(4, true);
    solve(8, false);
}
