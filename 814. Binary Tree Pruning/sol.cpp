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
    bool helper(TreeNode* root) {
        if(not root) return false;
        
        if(not root->left and not root->right)
            return root->val == 1;
        
        bool a = helper(root->left), b = helper(root->right);
        
        if(a and b) return true;
        
        if(not a) root->left = nullptr;
        if(not b) root->right = nullptr;
        
        if(a or b) return true;
        
        return root->val == 1;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(not helper(root))
            return nullptr;
        return root;
    }
};
