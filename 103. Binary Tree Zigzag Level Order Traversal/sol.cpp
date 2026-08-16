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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int sw = 0;
        
        while(!q.empty()) {
            int s = q.size();
            vector<int> tmp;
            while(s--) {
                TreeNode* cur = q.front(); q.pop();
                tmp.push_back(cur->val);
                    
                if(cur->left)
                    q.push(cur->left);
                
                if(cur->right)
                    q.push(cur->right);
            }
            if(sw)
                reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            sw = (sw + 1) % 2;
        }
        
        return ans;
    }
};

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

// --- alternate solution ---

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(not root)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        int sw = 0;
        vector<vector<int>> ans;
        
        while(not q.empty()) {
            int s = q.size();
            vector<int> tmp;
            
            while(s--) {
                TreeNode* cur = q.front(); q.pop();
                
                if(sw % 2)
                    tmp.insert(tmp.begin(), cur->val);
                
                else
                    tmp.push_back(cur->val);
                
                if(cur->left)
                    q.push(cur->left);
                
                if(cur->right)
                    q.push(cur->right);
            }
            
            sw++;
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
