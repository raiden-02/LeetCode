class Solution {
    vector<bool> vis;
    unordered_map<int, vector<int>> g;
    
    void dfs(int &node) {
        if(vis[node])
            return;
        
        vis[node] = true;
        for(int neigh : g[node])
            dfs(neigh);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        for(int i = 0; i < isConnected.size(); i++) {
            for(int j = 0; j < isConnected.size(); j++) {
                if(i != j && isConnected[i][j]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        vis = vector<bool>(isConnected.size());
        for(int i = 0; i < isConnected.size(); i++) {
            if(vis[i]) continue;
            dfs(i);
            ans += 1;
        }
        
        return ans;
    }
};

// --- alternate solution ---

//union find
class Solution {
    vector<int> parent;
    int ans = 0;
    
    void init(int n) {
        parent.resize(n);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        ans = n;
    }
    
    int find(int i) {
        return i == parent[i] ? i : find(parent[i]);
    }
    
    void merge(int i, int j) {
        int pi = find(i), pj = find(j);
        
        if(pi == pj)
            return;
        
        parent[pi] = pj;
        ans--;
    }
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int m = adj.size();
        init(m);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < i; j++) {
                if(adj[i][j])
                    merge(i, j);
            }
        }
        
        return ans;
    }
};

//dfs
