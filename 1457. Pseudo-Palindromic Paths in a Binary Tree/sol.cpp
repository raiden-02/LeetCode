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
    unordered_map<int, int> freq;
    int ans = 0;

    void helper(TreeNode* root) {
        if(!root) return;

        if(!root->left && !root->right) {
            freq[root->val]++;

            int cnt = 0;

            for(auto &[k, v] : freq) {
                if(v % 2 != 0) cnt++;
                if(cnt > 1) break;
            }
            
            if(cnt <= 1) ans++;
            
            freq[root->val]--;
            return;
        }
        
        freq[root->val]++;

        helper(root->left);
        helper(root->right);

        freq[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return ans;
    }
};
