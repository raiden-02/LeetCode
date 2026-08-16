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
    vector<TreeNode*> ans;
    unordered_map<string, int> mp;
    
    string helper(TreeNode* root) {
        if(not root) return ".";

        string left = helper(root->left), right = helper(root->right);
        string key = left + "," + right + "," + to_string(root->val);
        if(mp[key]++ == 1) ans.push_back(root);

        return key; 
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);

        return ans;
    }
};
