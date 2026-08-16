class Solution {
    int viscnt = 0;
    unordered_map<int, vector<int>> g;
    vector<bool> vis;

    void dfs(int cur) {
        for(int neigh : g[cur]) {
            if(!vis[neigh]) {
                viscnt++;
                vis[neigh] = true;
                dfs(neigh);
            }
        }
    }

public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {      
        vector<int> indeg(n);
        vector<int> ans;
        vis.resize(n, false);

        for(auto &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }

        
        for(int i = 0; i < n; i++) {
            if(viscnt == n) return ans;

            if(indeg[i] == 0 && !vis[i]) {
                vis[i] = true;
                viscnt++;
                dfs(i);
                ans.push_back(i);
            }
        }

        return ans;
    }
};
