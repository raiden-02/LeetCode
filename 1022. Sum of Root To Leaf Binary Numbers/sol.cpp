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
    
    void helper(TreeNode* root, int t) {
        if(not root) return;
        
        t = 2 * t + root->val;
        
        if(not root->left and not root->right) {
            ans += t;
            return;
        }
        
        helper(root->left, t);
        helper(root->right, t);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        helper(root, 0);
        return ans;
    }
};
