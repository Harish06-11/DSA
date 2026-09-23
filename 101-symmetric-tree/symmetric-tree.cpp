class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;

        if (left == nullptr || right == nullptr)
            return false;

        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        return isMirror(root->left, root->right);
    }
};
