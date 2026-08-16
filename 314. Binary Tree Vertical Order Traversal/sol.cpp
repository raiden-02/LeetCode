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
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root)
            return {};
        
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            TreeNode *cur = q.front().first;
            int pos = q.front().second; q.pop();
            mp[pos].push_back(cur->val);
            
            if(cur->left)
                q.push({cur->left, pos - 1});
            
            if(cur->right)
                q.push({cur->right, pos + 1});
        }
        
        vector<vector<int>> ans;
        for(auto &x : mp)
            ans.push_back(x.second);
        
        return ans;
    }
};
