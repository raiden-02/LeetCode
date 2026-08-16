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
    TreeNode* helper(string const& s, int &ind) {
        string val;
        
        while(ind < s.length() && s[ind] != '(' && s[ind] != ')')
            val += s[ind++];
        
        TreeNode *root = new TreeNode(stoi(val));
        
        if(s[ind] == '(') {
            ind++;
            root->left = helper(s, ind);
        }
        
        if(s[ind] == '(') {
            ind++;
            root->right = helper(s, ind);
        }
        ind++;
        
        return root; 
    }
public:
    TreeNode* str2tree(string s) {
        if(s.empty())
            return nullptr;
        
        int ind = 0;
        return helper(s, ind);
    }
};
