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
    int ans = 0;
    
    void dfs(TreeNode* node, int cur) {
        if(!node)
            return;
        
        cur = cur * 10 + node->val;
        
        if(!node->left and !node->right) {
            ans += cur;
            return;
        }
        
        dfs(node->left, cur);
        dfs(node->right, cur);
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        
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
    int ans;
    
    void helper(TreeNode* root, int s) {
        if(not root) return;
        
        s = s * 10 + root->val;
        
        if(not root->left and not root->right) {
            ans += s;
            return;
        }
        
        if(root->left) helper(root->left, s);
        if(root->right) helper(root->right, s);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(not root) return 0;
        
        ans = 0;
        helper(root, 0);
        
        return ans;
    }
};
