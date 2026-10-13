class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = build(start, i - 1);
            vector<TreeNode*> rightTrees = build(i + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};
