
class Solution {
public:
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int left, int right) {

        if (left > right)
            return NULL;

        // Root is the last element in postorder
        int rootVal = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootVal);

       
        int mid = mp[rootVal];

        
        root->right = solve(inorder, postorder, mid + 1, right);

        
        root->left = solve(inorder, postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        postIndex = n - 1;

        return solve(inorder, postorder, 0, n - 1);
    }
};
