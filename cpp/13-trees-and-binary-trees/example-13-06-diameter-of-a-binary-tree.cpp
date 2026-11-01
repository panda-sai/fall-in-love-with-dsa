// Fall in Love With DSA, Example 13.6: Diameter of a binary tree
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

// ---- helpers used by the test below (not printed in the book) ----
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {
    }
};
TreeNode* sample() {
    TreeNode* r = new TreeNode(8);
    r->left = new TreeNode(3);
    r->right = new TreeNode(10);
    r->left->left = new TreeNode(1);
    r->left->right = new TreeNode(6);
    r->right->right = new TreeNode(14);
    return r;
}

// ---- code from the book ----
int best = 0;

// returns the height, and updates best on the way
int heightAndDiameter(TreeNode* root) {
    if (root == nullptr) return -1;
    int lh = heightAndDiameter(root->left);
    int rh = heightAndDiameter(root->right);
    best = max(best, (lh + 1) + (rh + 1));
    return 1 + max(lh, rh);
}

// ---- a small test, so you can run this example ----
int main() {
    heightAndDiameter(sample());
    cout << "diameter = " << best << endl;
}
