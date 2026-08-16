//O(N) time O(N) space Intuitive
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
    
    void helper(TreeNode *root) {
        if(not root)
            return;
        
        arr.push_back(root->val);
        
        helper(root->left), helper(root->right);
    }
public:
    void flatten(TreeNode* root) {
        if(not root)
            return;
        
        helper(root);
        
        root->left = nullptr, root->right = nullptr;
        TreeNode *tmp = root;
        
        for(int i = 1; i < arr.size(); i++)
            tmp->right = new TreeNode(arr[i]), tmp = tmp->right;
        
    }
};

//O(N) time O(1) space morris traversal
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
    //morris traversal
    void flatten(TreeNode* root) {
        TreeNode *prev;
        
        while(root) {
            if(not root->left) {
                root = root->right;
                continue;
            }
            
            prev = root->left;
            
            while(prev->right)
                prev = prev->right;
            
            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            
            root = root->right;
        }
    }
};
