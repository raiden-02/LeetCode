class Solution {
    vector<bool> vis;
    vector<int> ans, countCloserNodes;
    vector<vector<int>> g;
    int n;
    //formula: parent_sum - closerNodes + fartherNodes;
    
    
    int dfs(int cur) {
        int closerNodes = 1;
        
        for(int &child : g[cur]) {
            if(not vis[child]) {
                vis[child] = true;
                
                int childNodesCount = dfs(child);
                closerNodes += childNodesCount;
                
                ans[0] += childNodesCount;
            }
        }
        
        return countCloserNodes[cur] = closerNodes;
    }
    
    void dfs2(int cur) {
        for(int &child : g[cur]) {
            if(not vis[child]) {
                vis[child] = true;
                
                ans[child] = ans[cur] - countCloserNodes[child] + (n - countCloserNodes[child]);
                
                dfs2(child);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        ans.resize(n), g.resize(n), countCloserNodes.resize(n);
        
        for(auto &x : edges)
            g[x[0]].push_back(x[1]), g[x[1]].push_back(x[0]);
        
        vis.assign(n, false);
        vis[0] = true, dfs(0);
        
        vis.assign(n, false);
        vis[0] = true, dfs2(0);
        
        return ans;
    }
};
