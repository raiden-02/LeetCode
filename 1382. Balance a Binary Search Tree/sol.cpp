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
    vector<int> arr;
    
    void inorder(TreeNode* root) {
        if(not root) return;
        
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* helper(int l, int r) {
        if(l > r) return nullptr;
        
        int mid = (l + r) >> 1;
        TreeNode* root = new TreeNode(arr[mid]);
        
        root->left = helper(l, mid - 1);
        root->right = helper(mid + 1, r);
        
        return root;
    } 
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        
        return helper(0, arr.size() - 1);
    }
};
