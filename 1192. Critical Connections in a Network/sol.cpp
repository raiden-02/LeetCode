class Solution {
    vector<vector<int>> g;
    int time;
    vector<int> vtime, low;
    vector<vector<int>> ans;
    vector<bool> vis;
    
    void dfs(int cur, int par) {
        vis[cur] = true;
        vtime[cur] = low[cur] = ++time;
        
        for(int neigh : g[cur]) {
            if(neigh == par) continue;
            
            if(!vis[neigh]) {
                dfs(neigh, cur);
                low[cur] = min(low[cur], low[neigh]);
                
                if(vtime[cur] < low[neigh])
                    ans.push_back({cur, neigh});
            }
            
            else//backedge other than the edge of parent found
                low[cur] = min(low[cur], vtime[neigh]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        g.resize(n);
        vtime.resize(n), low.resize(n), vis.resize(n);
        time = 0;
        
        for(auto &x : connections)
            g[x[0]].push_back(x[1]), g[x[1]].push_back(x[0]);
        
        dfs(0, -1);
        
        return ans;
    }
};
