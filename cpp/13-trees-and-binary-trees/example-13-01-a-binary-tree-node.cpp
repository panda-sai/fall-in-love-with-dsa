// Fall in Love With DSA, Example 13.1: A binary tree node
// This is a fragment from the book, not a complete program.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v)
        : val(v), left(nullptr), right(nullptr) {}
};

// Building this tree:      8
//                        /   \
//                       3     10
//                      / \      \
//                     1   6      14
TreeNode* root = new TreeNode(8);
root->left = new TreeNode(3);
root->right = new TreeNode(10);
root->left->left = new TreeNode(1);
root->left->right = new TreeNode(6);
root->right->right = new TreeNode(14);
