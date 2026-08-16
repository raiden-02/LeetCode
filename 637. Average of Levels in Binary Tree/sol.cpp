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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            double avg = 0, l = s;
            while(s--) {
                auto cur = q.front(); q.pop();
                avg += cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            avg /= l;
            ans.push_back(avg);
        }
        return ans;
    }
};
