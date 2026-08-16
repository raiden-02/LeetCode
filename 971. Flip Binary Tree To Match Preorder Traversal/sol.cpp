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
    
    void helper(TreeNode *root, vector<int> const& voyage, int &i) {
        if(!root)
            return;
        
        if(root->val != voyage[i]) {
            ans = {-1};
            return;
        }
        
        i++;
        
        if(i < voyage.size() && root->left && root->left->val != voyage[i]) {
            ans.push_back(root->val);
            helper(root->right, voyage, i); //flip inspect the right node first
            helper(root->left, voyage, i);
            return;
        }
        
        helper(root->left, voyage, i); //dont flip
        helper(root->right, voyage, i);
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int i = 0;
        helper(root, voyage, i);
        
        if(!ans.empty() && ans[0] == -1)
            ans = {-1};
        
        return ans;
    }
};
