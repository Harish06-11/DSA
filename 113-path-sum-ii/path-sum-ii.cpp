class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* node, int targetSum, vector<int>& path) {
        if (node == nullptr)
            return;

        path.push_back(node->val);

        // Check if it's a leaf and the path sum equals targetSum
        if (node->left == nullptr && node->right == nullptr) {
            if (targetSum == node->val) {
                result.push_back(path);
            }
        } else {
            dfs(node->left, targetSum - node->val, path);
            dfs(node->right, targetSum - node->val, path);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }
};
