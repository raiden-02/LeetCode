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
    vector<int> sortedVals;
    int ind = 0;
    
    void inorder(TreeNode* root) {
        if(not root) return;
        
        inorder(root->left);
        sortedVals.push_back(root->val);
        inorder(root->right);
    }
    
    void assign(TreeNode* root) {
        if(not root) return;
        
        assign(root->left);
        root->val = sortedVals[ind++];
        assign(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(sortedVals.begin(), sortedVals.end());
        assign(root);
    }
};
