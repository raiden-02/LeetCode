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
    bool helper(TreeNode* root, TreeNode* subroot) {
        if(not root and not subroot) return true;
        if(not root or not subroot) return false;
        
        return root->val == subroot->val and helper(root->left, subroot->left) and helper(root->right, subroot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(not subroot) return true;
        if(not root) return false;
        
        if(helper(root, subroot)) return true;
        
        return isSubtree(root->left, subroot) or isSubtree(root->right, subroot);
    }
};
