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
        if(not root)
            return;
        
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        
        int l = 0, r = arr.size() - 1;
        
        while(l < r) {
            int s = arr[l] + arr[r];
            
            if(s > k)
                r--;
            else if(s < k)
                l++;
            else
                return true;
        }
        
        return false;
    }
};
