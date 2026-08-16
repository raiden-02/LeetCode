//intuitive find bridges and the answer is the first edge from the end which is not a bridge
class Solution {
    vector<bool> vis;
    vector<int> low, vtime;
    int time;
    set<vector<int>> ans;
    vector<vector<int>> g;
    
    void dfs(int cur, int par) {
        vis[cur] = true;
        vtime[cur] = low[cur] = time++;
        
        for(int &neigh : g[cur]) {
            if(neigh == par) continue;
            
            if(not vis[neigh]) {
                dfs(neigh, cur);
                
                low[cur] = min(low[cur], low[neigh]);
                
                if(low[neigh] > vtime[cur])
                    ans.insert({min(cur, neigh), max(neigh, cur)});
            }
            
            else
                low[cur] = min(low[cur], vtime[neigh]);
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        g.resize(n + 1);
        
        for(auto &x : edges)
            g[x[0]].push_back(x[1]), g[x[1]].push_back(x[0]);
        
        vtime.resize(n + 1), low.resize(n + 1), vis.resize(n + 1, false), time = 0;
        
        for(int i = 1; i <= n; i++) {
            if(not vis[i])
                dfs(i, i);
        }
        
        for(int i = n - 1; i >= 0; i--) {
            int mn = min(edges[i][0], edges[i][1]), mx = max(edges[i][0], edges[i][1]);
            
            vector<int> t = {mn, mx};
            
            if(ans.find(t) == ans.end())
                return t;
        }
        
        return {};
    }
};


//union find

// --- alternate solution ---

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        
        for(auto &x : edges) {
            int a = x[0], b = x[1];
            
            while(a != parent[a]) a = parent[a];
            while(b != parent[b]) b = parent[b];
            
            if(a == b)
                return x;
            
            parent[a] = b;
        }
        
        return {};
    }
};
