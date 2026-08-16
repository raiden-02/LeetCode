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
    int ans;
    
    int helper(TreeNode* root) {
        if(not root) return 0;
        
        int l = helper(root->left), r = helper(root->right), s = l + r + root->val;
        ans += abs(r - l);
        
        return s;
    }
public:
    int findTilt(TreeNode* root) {
        helper(root);
        return ans;
    }
};
