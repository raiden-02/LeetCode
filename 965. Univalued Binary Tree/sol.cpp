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
    bool helper(TreeNode* root, int const& val) {
        if(not root) return true;
        
        if(root->val != val) return false;
        
        return helper(root->left, val) and helper(root->right, val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(not root) return true;
        
        return helper(root, root->val);
    }
};
