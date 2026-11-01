// Fall in Love With DSA, Example 13.4: Preorder, inorder and postorder
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
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";     // root first
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";     // root between
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";     // root last
}

// ---- a small test, so you can run this example ----
int main() {
    TreeNode* r = sample();
    cout << "preorder:  ";
    preorder(r);
    cout << endl;
    cout << "inorder:   ";
    inorder(r);
    cout << endl;
    cout << "postorder: ";
    postorder(r);
    cout << endl;
}
