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
    vector<vector<int>> ans;
    
    int helper(TreeNode* root) {
        if(not root) return -1;
        
        int left = helper(root->left), right = helper(root->right);
        int curlvl = max(left, right) + 1;
        
        if(ans.size() == curlvl) ans.push_back({});
        
        ans[curlvl].push_back(root->val);
        return curlvl;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        helper(root);
        return ans;
    }
};
