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
    unordered_map<string, vector<TreeNode*>> mp;
public:
    vector<TreeNode*> helper(int s, int e) {
        string key = to_string(s) + to_string(e);
        if(mp.find(key) != mp.end()) return mp[key];
        
        vector<TreeNode*> ret;
        if(s > e) {
            ret.push_back(NULL);
            mp[key] = ret;
            return ret;
        }
        if(s == e) {
            TreeNode* root = new TreeNode(s);
            ret.push_back(root);
            mp[key] = ret;
            return ret;
        }
        for(int i = s; i <= e; i++) {
            vector<TreeNode*> left = helper(s, i - 1), right = helper(i + 1, e);
            for(TreeNode* l : left) {
                for(TreeNode* r : right) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ret.push_back(root);
                }
            }
        }
        mp[key] = ret;
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        return n <= 0 ? vector<TreeNode*>() : helper(1, n);
    }
};
