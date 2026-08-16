/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool pf = false, qf = false;

    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        
        TreeNode* l = helper(root->left, p, q), *r = helper(root->right, p, q);

        if(root == p) {
            pf = true;
            return p;
        }
        
        if(root == q) {
            qf = true;
            return q;
        }

        if(!l) return r;
        if(!r) return l;

        return root;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = helper(root, p, q);
        return pf && qf ? ans : nullptr;
    }
};
