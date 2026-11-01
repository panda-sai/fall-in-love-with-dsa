// Fall in Love With DSA, Example 4.7: Row sums of a matrix

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += grid[i][j];
        }
        cout << "Row " << i << " sum = " << rowSum
             << endl;
    }
    return 0;
}
