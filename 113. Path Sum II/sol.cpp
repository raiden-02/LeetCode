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
    vector<vector<int>> ans;
    
    void helper(TreeNode* root, int s, int const& target, vector<int> tmp) {
        s += root->val;
        tmp.push_back(root->val);
        
        if(not root->left and not root->right) {
            if(s == target)
                ans.push_back(tmp);
            return;
        }
        
        if(root->left) helper(root->left, s, target, tmp);
        if(root->right) helper(root->right, s, target, tmp);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(not root)
            return {};
        
        helper(root, 0, targetSum, {}); 
        
        return ans;
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
    vector<vector<int>> ans;
    
    void helper(TreeNode* root, int const& tar, int s, vector<int> tmp) {
        if(not root) return;
        
        if(not root->left and not root->right) {
            if(s + root->val == tar) {
                tmp.push_back(root->val);
                ans.push_back(tmp);
            }
            return;
        }
        
        tmp.push_back(root->val);
        helper(root->left, tar, s + root->val, tmp);
        helper(root->right, tar, s + root->val, tmp);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum, 0, {});
        return ans;
    }
};

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
