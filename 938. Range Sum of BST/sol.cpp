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
public:
    int rangeSumBST(TreeNode* root, int const& low, int const& high) {
        if(not root)
            return 0;
        
        int ans = 0;
        
        if(root->val >= low and root->val <= high) ans = root->val;
        
        if(root->val < low) return ans + rangeSumBST(root->right, low, high);
        if(root->val > high) return ans + rangeSumBST(root->left, low, high);
        
        return ans + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
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
    int s = 0;
    
    void helper(TreeNode*  root, int const& low, int const& high) {
        if(not root) return;
        
        if(root->val > high) helper(root->left, low, high);
        
        else if(root->val < low) helper(root->right, low, high);
        
        else {
            s += root->val;
            helper(root->left, low, high);
            helper(root->right, low, high);
        }
        
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root, low, high);
        return s;
    }
};
