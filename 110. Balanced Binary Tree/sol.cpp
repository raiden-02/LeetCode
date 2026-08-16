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
    bool ans = true;
    int helper(TreeNode* root) {
        if(not root) return 0;
        
        int left = helper(root->left), right = helper(root->right);
        
        if(abs(left - right) > 1) {
            ans = false;
            return 0;
        }
        
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        helper(root);
        return ans;
    }
};
