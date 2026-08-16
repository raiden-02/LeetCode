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
    string sleft, sright;
    bool f = true;

    TreeNode* findlca(TreeNode* root, int startValue, int destValue) {
        if(not root or root->val == startValue or root->val == destValue)
            return root;
        
        TreeNode* left = findlca(root->left, startValue, destValue), *right = findlca(root->right, startValue, destValue);

        if(not left) return right;
        if(not right) return left;

        return root;
    }

    void find(TreeNode* root, int val, string &s) {
        if(not root) return;

        if(root->val == val) {
            f ? sleft = s : sright = s;
            return;
        }

        s.push_back('L');
        find(root->left, val, s);
        s.pop_back();

        s.push_back('R');
        find(root->right, val, s);
        s.pop_back();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findlca(root, startValue, destValue);
        string s;
        find(lca, startValue, s);
        f = false;
        find(lca, destValue, s);

        for(int i = 0; i < sleft.length(); i++) sleft[i] = 'U';

        return sleft + sright;
    }
};
