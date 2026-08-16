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
    int ans;
    vector<int> helper(TreeNode* root, int const& distance) {
        if(not root) return {};
        
        if(not root->left and not root->right)
            return {1};
        
        vector<int> left = helper(root->left, distance), right = helper(root->right, distance);
        
        for(int &x : left) {
            for(int &y : right) {
                if(x + y <= distance)
                    ans++;
            }
        }
        
        vector<int> ans;
        
        for(auto &x : left)
            if(x + 1 <= distance) ans.push_back(x + 1);
        
        for(auto &x : right)
            if(x + 1 <= distance) ans.push_back(x + 1);
        
        return ans;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        vector<int> dists = helper(root, distance);
        
        return ans;
    }
};
