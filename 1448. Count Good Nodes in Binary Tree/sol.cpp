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
    int helper(TreeNode* root, int maxm) {
        if(not root)
            return 0;
        
        if(maxm <= root->val)
            return 1 + helper(root->left, root->val) + helper(root->right, root->val);
        
        return helper(root->left, maxm) + helper(root->right, maxm);
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
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
    int goodNodes(TreeNode* root, int maxm = -1e4 - 1) {
        if(not root) return 0;
        
        return (root->val >= maxm) + goodNodes(root->left, max(root->val, maxm)) + goodNodes(root->right, max(root->val, maxm));
    }
};
