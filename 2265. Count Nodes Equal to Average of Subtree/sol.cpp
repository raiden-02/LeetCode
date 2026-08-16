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
    pair<int, int> helper(TreeNode* root) {
        if(!root) return {0, 0};

        if(!root->left && !root->right) {
            ans++;
            return {root->val, 1};
        }

        pair<int, int> cur = {root->val, 1};
        auto left = helper(root->left);
        auto right = helper(root->right);

        cur.first += left.first + right.first;
        cur.second += left.second + right.second;

        
        if(cur.first / cur.second == root->val) ans++;

        return cur;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        
        return ans;
    }
};
