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
    vector<int> arr, cache;
    int i = 0;
    
    void helper(TreeNode* root) {
        if(not root) return;
        
        helper(root->right);
        arr.push_back(root->val);
        helper(root->left);
    }
    
    void ansHelper(TreeNode* root) {
        if(not root) return;
        
        ansHelper(root->right);
        root->val = cache[i++];
        ansHelper(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        int s = 0;
        
        for(int x : arr)
            s += x, cache.push_back(s);
        
        ansHelper(root);
        
        return root;
    }
};
