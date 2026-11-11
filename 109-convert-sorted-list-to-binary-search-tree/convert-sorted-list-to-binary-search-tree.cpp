
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;

        // Store linked list elements in array
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }

        return build(arr, 0, arr.size() - 1);
    }

    TreeNode* build(vector<int>& arr, int left, int right) {
        if (left > right)
            return nullptr;

        // Find middle element
        int mid = left + (right - left) / 2;

        // Create root node
        TreeNode* root = new TreeNode(arr[mid]);

        // Recursively build left and right subtrees
        root->left = build(arr, left, mid - 1);
        root->right = build(arr, mid + 1, right);

        return root;
    }
};
