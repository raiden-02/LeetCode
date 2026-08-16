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
    int ans = -1;

    void helper(TreeNode* root, int maxm, int minm) {
        if(!root) return;

        ans = max(ans, abs(maxm - root->val));
        ans = max(ans, abs(minm - root->val));

        helper(root->left, max(maxm, root->val), min(minm, root->val));
        helper(root->right, max(maxm, root->val), min(minm, root->val));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;

        helper(root->left, root->val, root->val);
        helper(root->right, root->val, root->val);

        return ans;
    }
};
