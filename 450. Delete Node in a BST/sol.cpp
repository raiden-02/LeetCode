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
    TreeNode* helper(TreeNode* root) {
        while(root->left)
            root = root->left;
        
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(not root) return nullptr;
        
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        
        else {
            if(not root->left) return root->right;
            if(not root->right) return root->left;
        
            TreeNode* minNode = helper(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, root->val);
        }
        
        return root;
    }
};


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
