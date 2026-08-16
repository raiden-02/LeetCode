class Solution {
    vector<vector<int>> g;
    vector<bool> vis;
    
    bool dfs(int node, int const& dest) {
        if(node == dest and g[node].empty())
            return true;
        
        if(node != dest and g[node].empty())
            return false;
        
        bool ans = true;
        vis[node] = true;
        
        for(int &neigh : g[node]) {
            if(vis[neigh]) { ans = false; continue; }
            ans = ans and dfs(neigh, dest);
        }
        
        vis[node] = false;
        return ans;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        g.resize(n), vis.resize(n, false);
        
        for(auto &x : edges)
            g[x[0]].push_back(x[1]);
        
        return dfs(source, destination);
    }
};

// --- alternate solution ---

class Solution {
    vector<vector<int>> g;
    vector<bool> vis;
    
    bool dfs(int source, int const& dest) {
        if(vis[source] or (source != dest and g[source].empty()))
            return false;
        
        if(source == dest and g[source].empty())
            return true;
        
        bool ans = true;
        vis[source] = true;
        
        for(int &neigh : g[source])
            ans = ans and dfs(neigh, dest);
        
        vis[source] = false;
        return ans;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vis.resize(n, false);
        g.resize(n);
        
        for(auto &x : edges)
            g[x[0]].push_back(x[1]);
        
        return dfs(source, destination);
    }
};
