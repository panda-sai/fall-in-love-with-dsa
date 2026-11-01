// Fall in Love With DSA, Example 14.1: Searching a BST
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
TreeNode* search(TreeNode* root, int target) {
    while (root != nullptr && root->val != target) {
        if (target < root->val) root = root->left;
        else root = root->right;
    }
    return root;               // nullptr if not found
}

// ---- a small test, so you can run this example ----
int main() {
    TreeNode* r = bstFrom({8, 3, 10, 1, 6, 14});
    cout << "search 6: " << (search(r, 6) ? "found" : "not found")
         << endl;
    cout << "search 7: " << (search(r, 7) ? "found" : "not found")
         << endl;
}
