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
    
    int helper(TreeNode *root) {
        if(not root)
            return 0;
        
        int l = helper(root->left), r = helper(root->right);
        
        if(l == -1 or r == -1) { //at least one child does not have camera we need to put a camera here
            ans++;
            return 1;
        }
        
        if(l == 1 or r == 1) //at least one child has camera no need to put camera here  
            return 0;
        
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        return helper(root) == -1 ? ans + 1 : ans;
    }
};
