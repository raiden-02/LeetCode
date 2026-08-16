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
    void helper(TreeNode* root, int val, int depth) {
        if(not root) return;
        
        if(depth - 1 == 1) {
            TreeNode* origLeft = root->left, *origRight = root->right;
            root->left = new TreeNode(val, origLeft, nullptr);
            root->right = new TreeNode(val, nullptr, origRight);
            return;
        }
        
        helper(root->left, val, depth - 1);
        helper(root->right, val, depth - 1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* nn = new TreeNode(val, root, nullptr);
            return nn;
        }
        
        helper(root, val, depth);
        return root;
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
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root)
            return nullptr;
        
        if(d == 1) {
            TreeNode* nroot = new TreeNode(v, root, nullptr);
            return nroot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int l = 1;
        while(!q.empty()) {
            if(l == d - 1) {
                int s = q.size();
                while(s--) {
                    TreeNode* node = q.front(); q.pop();
                    TreeNode *l = node->left, *r = node->right;
                    node->left = new TreeNode(v); node->right = new TreeNode(v);
                    node->left->left = l; node->right->right = r;
                }
                return root;
            }
            int s = q.size();
            while(s--) {
                TreeNode* cur = q.front(); q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            l++;
        }
        return root;
    }
};
