//intuitive solution O(v + e)
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
    string ans;
    
    void dfs(TreeNode *node, string val) {
        if(not node)
            return;
        
        val = char(node->val + 'a') + val;
        
        if(not node->left and not node->right) {
            ans = min(ans, val);
            return;
        }
        
        dfs(node->left, val);
        dfs(node->right, val);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        ans.resize(1000, 'z');
        
        dfs(root, "");
        
        return ans;
    }
};
