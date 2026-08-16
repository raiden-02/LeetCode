class Solution {
    unordered_map<int, int> mp;
    
    int helper(TreeNode* root) {
        if(not root) return 0;
        
        int s = root->val + helper(root->left) + helper(root->right);
        mp[s]++;
        
        return s;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        int s = helper(root);
        
        if(s == 0)
            return mp[s] > 1;
        
        return s % 2 == 0 and mp[s / 2];
    }
};
