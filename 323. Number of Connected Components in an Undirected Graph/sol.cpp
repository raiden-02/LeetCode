class Solution {
    int ans = 0;
    vector<bool> vis;
    vector<vector<int>> g;
    
    void dfs(int &node) {
        if(vis[node])
            return;
        
        vis[node] = true;
        for(int &neigh : g[node])
            dfs(neigh);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        g = vector<vector<int>>(n);
        
        for(auto &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        vis = vector<bool>(n);
        for(int i = 0; i < n; i++) {
            if(vis[i])
                continue;
            dfs(i);
            ans++;
        }
        
        return ans;
    }
};

// --- alternate solution ---

//union find
class Solution {
    vector<int> parent;
    int ans = 0;
    
    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }
    
    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        
        ans--;
        parent[px] = py;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n), ans = n;
        
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(auto &edge : edges)
            merge(edge[0], edge[1]);
        
        return ans;
    }
};

//dfs
