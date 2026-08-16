class Solution {
    vector<vector<int>> g;
    vector<bool> vis;
    
    void dfs(int cur, long long &count) {
        for(int neigh : g[cur]) {
            if(!vis[neigh]) {
                vis[neigh] = true;
                count++;
                dfs(neigh, count);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
       long long rem = n, ans = 0;
       g.resize(n);
       vis.resize(n, false);

       for(auto &edge : edges) {
           g[edge[0]].push_back(edge[1]);
           g[edge[1]].push_back(edge[0]);
       }

       for(int i = 0; i < n; i++) {
           if(!vis[i]) {
               vis[i] = true;
               long long count = 1;
               dfs(i, count);
               ans += count * (rem - count);
               rem -= count;
           }
       }

       return ans;
    }
};
