// Fall in Love With DSA, Example 14.6: Lowest common ancestor in a BST
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
TreeNode* preInsert(TreeNode* r, int v) {
    if (!r) return new TreeNode(v);
    if (v < r->val)
        r->left = preInsert(r->left, v);
    else
        r->right = preInsert(r->right, v);
    return r;
}
TreeNode* bstFrom(vector<int> v) {
    TreeNode* r = nullptr;
    for (int x : v) r = preInsert(r, x);
    return r;
}
void printIn(TreeNode* r) {
    if (!r) return;
    printIn(r->left);
    cout << r->val << " ";
    printIn(r->right);
}

// ---- code from the book ----
TreeNode* lca(TreeNode* root, int p, int q) {
    while (root != nullptr) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root;          // they split here
    }
    return nullptr;
}

// ---- a small test, so you can run this example ----
int main() {
    TreeNode* r = bstFrom({8, 3, 10, 1, 6, 14, 4, 7, 13});
    cout << "lca(4, 7) = " << lca(r, 4, 7)->val << endl;
    cout << "lca(4, 14) = " << lca(r, 4, 14)->val << endl;
}
