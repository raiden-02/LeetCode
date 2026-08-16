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
    double ans;
    
    pair<double, double> helper(TreeNode* root) {
        if(not root) return {0, 0};
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        pair<double, double> ret = {left.first + right.first + 1, left.second + right.second + root->val};
        ans = max(ans, ret.second / ret.first);
        
        return ret;
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        ans = 0;
        auto k = helper(root);
        
        return ans;
    }
};
