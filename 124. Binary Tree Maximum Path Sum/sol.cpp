/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = INT_MIN;
    int helper(TreeNode* root) {
        if(not root)
            return 0;
        
        int left = max(0, helper(root->left)), right = max(0, helper(root->right));
        ans = max(ans, left + right + root->val);

        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
