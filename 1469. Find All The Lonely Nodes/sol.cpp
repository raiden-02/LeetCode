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
    vector<int> ans;
    
    void helper(TreeNode* root) {
        if(not root) return;
        
        if(root->left and not root->right) ans.push_back(root->left->val);
        
        else if(root->right and not root->left) ans.push_back(root->right->val);
        
        helper(root->left), helper(root->right);
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        helper(root);
        return ans;
    }
};
