//iterative inorder traversal
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
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *tmp = root;
        stack<TreeNode*> st;
        vector<TreeNode*> ans;
        
        while(tmp || !st.empty()) {
            while(tmp) {
                st.push(tmp);
                tmp = tmp->left;
            }
            
            tmp = st.top(); st.pop();
            
            ans.push_back(tmp);
            
            tmp = tmp->right;
            
        }
        
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == p && i + 1 < ans.size())
                return ans[i + 1];
        }
        
        return nullptr;
    }
};
