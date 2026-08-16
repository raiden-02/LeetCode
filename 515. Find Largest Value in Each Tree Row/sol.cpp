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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        ans.push_back(root->val);
        
        while(!q.empty()) {
            int s = q.size();
            int maxm = numeric_limits<int>::min();

            while(s--) {
                TreeNode* cur = q.front(); q.pop();

                if(cur->left)
                    q.push(cur->left), maxm = max(maxm, cur->left->val);
                if(cur->right)
                    q.push(cur->right), maxm = max(maxm, cur->right->val);  
            }

            if(!q.empty()) ans.push_back(maxm);
        }

        return ans;
    }
};
