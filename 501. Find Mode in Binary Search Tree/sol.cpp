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
    int freq = 0, prev = INT_MIN, maxf = 0;
    
    void helper(TreeNode* root) {
        if(not root) return;
        
        helper(root->left);
        
        if(root->val == prev) freq++;
        else freq = 1;
        
        if(freq > maxf) {
            ans.clear();
            maxf = freq;
            ans.push_back(root->val);
        }
        
        else if(freq == maxf)
            ans.push_back(root->val);
        
        prev = root->val;
        
        helper(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        helper(root);
        return ans;
    }
};
