// Fall in Love With DSA, Example 17.5: Neighbours of a cell in a grid
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
int dr[4] = {-1, 1, 0, 0};  // up, down, left, right
int dc[4] = {0, 0, -1, 1};

void printNeighbours(int r, int c, int rows, int cols) {
    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        bool inside = nr >= 0 && nr < rows
                      && nc >= 0 && nc < cols;
        if (inside)
            cout << "(" << nr << ", " << nc << ") ";
    }
    cout << endl;
}

// ---- a small test, so you can run this example ----
int main() {
    printNeighbours(0, 0, 3, 3);
    printNeighbours(1, 1, 3, 3);
}
