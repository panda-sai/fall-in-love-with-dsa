// Fall in Love With DSA, Example 14.4: Deleting from a BST
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
TreeNode* remove(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    if (key < root->val) {
        root->left = remove(root->left, key);
    } else if (key > root->val) {
        root->right = remove(root->right, key);
    } else {                                   // found
        if (root->left == nullptr) {  // cases 1, 2
            TreeNode* r = root->right;
            delete root;
            return r;
        }
        if (root->right == nullptr) {          // case 2
            TreeNode* l = root->left;
            delete root;
            return l;
        }
        TreeNode* succ = root->right;          // case 3
        while (succ->left != nullptr) succ = succ->left;
        root->val = succ->val;
        root->right = remove(root->right, succ->val);
    }
    return root;
}

// ---- a small test, so you can run this example ----
int main() {
    TreeNode* r = bstFrom({8, 3, 10, 1, 6, 14, 4, 7, 13});
    r = remove(r, 3);
    cout << "after removing 3:  ";
    printIn(r);
    cout << endl;
    r = remove(r, 10);
    cout << "after removing 10: ";
    printIn(r);
    cout << endl;
}
