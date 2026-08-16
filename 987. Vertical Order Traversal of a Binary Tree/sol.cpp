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
    map<int, map<int, vector<int>>> mp;
    
    void dfs(TreeNode* root, int key, int lvl) {
        if(not root) return;
        
        mp[key][lvl].push_back(root->val);
        
        dfs(root->left, key - 1, lvl + 1);
        dfs(root->right, key + 1, lvl + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        
        vector<vector<int>> ans;
        
        for(auto &x : mp) {
            vector<int> tmp;
            
            for(auto &y : x.second) {
                sort(y.second.begin(), y.second.end());
                for(int z : y.second) tmp.push_back(z);
            }
            
            ans.push_back(tmp);
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
    map<int, map<int, vector<int>>> mp;
    
    void helper(TreeNode* root, int val, int row) {
        if(not root) return;
        
        mp[val][row].push_back(root->val);
        helper(root->left, val - 1, row + 1);
        helper(root->right, val + 1, row + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(not root) return {};
        
        helper(root, 0, 0);
        
        vector<vector<int>> ret;
        
        for(auto &x : mp) {
            vector<int> tmp;
            
            for(auto &y : x.second) {
                sort(y.second.begin(), y.second.end());
                for(int z : y.second) tmp.push_back(z);
            }
            
            ret.push_back(tmp);
        }
        
        return ret;
    }
};
