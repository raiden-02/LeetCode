//intuitive
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
    TreeNode* ret;
    
    void helper(TreeNode* root) {
        if(not root) return;
        
        helper(root->left);
        
        ret->right = new TreeNode(root->val);
        ret = ret->right;
        
        helper(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        ret = new TreeNode(-1);
        TreeNode* out = ret;
        
        helper(root);
        return out->right;
    }
};

//optmized
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
    TreeNode* increasingBST(TreeNode* root, TreeNode* head = nullptr) {
        if(not root) return head;
        
        TreeNode* ans = increasingBST(root->left, root);
        root->left = nullptr;
        root->right = increasingBST(root->right, head);
        
        return ans;
    }
};
