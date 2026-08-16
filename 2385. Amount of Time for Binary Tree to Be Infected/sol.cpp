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
    unordered_map<int, vector<int>> g;

    void makeGraph(TreeNode* root) {
        if(!root) return;
        if(root->left) {
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
        }

        if(root->right) {
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
        }

        makeGraph(root->left);
        makeGraph(root->right);
    }


public:
    int amountOfTime(TreeNode* root, int start) {
        makeGraph(root);

        queue<int> q;
        unordered_set<int> vis;

        int ans = 0;
        q.push(start);
        vis.insert(start);

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int cur = q.front();
                q.pop();

                for(int neigh : g[cur]) {
                    if(vis.find(neigh) != vis.end()) continue;

                    q.push(neigh);
                    vis.insert(neigh);
                }
            }

            ans++;
        }

        return ans - 1;
    }
};
