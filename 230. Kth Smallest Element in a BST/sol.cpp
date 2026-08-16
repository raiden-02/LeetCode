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
    int cnt = 0, val = -1;
    
    void helper(TreeNode* root, int const& k) {
        if(not root) return;
        
        helper(root->left, k);
        
        cnt++;
        if(cnt == k) {
            val = root->val;
            return;
        }
        
        helper(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return val;
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
    int k, ans = -1;
    
    void helper(TreeNode* root) {
        if(not root) return;
        
        helper(root->left);
        k--;
        
        if(k == 0) {
            ans = root->val;
            return;
        }
        
        helper(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        helper(root);
        return ans;
    }
};
