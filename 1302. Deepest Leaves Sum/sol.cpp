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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        
        while(!q.empty()) {
            int s = q.size();
            ans = 0;
            
            while(s--) {
                TreeNode* cur = q.front(); q.pop();
                ans += cur->val;
                
                if(cur->left)
                    q.push(cur->left);
                
                if(cur->right)
                    q.push(cur->right);
            }
        }
        
        return ans;
    }
};
