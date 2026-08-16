/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
1. Convert the tree into a graph (bfs)
2. Do regular bfs on the target node k times
*/

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<int, vector<int>> g;
        queue<TreeNode*> q;
        q.push(root);
        
        //create graph
        while(!q.empty()) {
            TreeNode *cur = q.front(); q.pop();
            
            if(cur->left)
                q.push(cur->left), g[cur->val].push_back(cur->left->val), g[cur->left->val].push_back(cur->val);
            
            if(cur->right)
                q.push(cur->right), g[cur->val].push_back(cur->right->val), g[cur->right->val].push_back(cur->val);
                
        }

        //bfs from target
        queue<int> p;
        p.push(target->val);
        vector<int> ans;
        unordered_set<int> vis;
        
        while(!p.empty()) {
            if(K == 0) {
                while(!p.empty())
                    ans.push_back(p.front()), p.pop();
                break;
            }
            int s = p.size();
            
            while(s--) {
                int cur = p.front(); p.pop();
                vis.insert(cur);
                
                for(int &neigh : g[cur]) {
                    if(vis.find(neigh) != vis.end()) continue;
                    p.push(neigh);
                }
            }
            K--;
        }
        return ans;
    }
};
