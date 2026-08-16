class Solution {
    vector<vector<int>> g;
    int ans = 0;
    vector<bool> vis;

    bool dfs(int x, vector<bool> const& apple) {
        bool gf = false;

        for(int neigh : g[x]) {
            if(vis[neigh]) continue;

            vis[neigh] = true;
            bool f = dfs(neigh, apple);
            gf |= f;
            if(f) ans += 2;
        }

        return gf or apple[x];
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        g.resize(n), vis.resize(n);

        for(auto &x : edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        vis[0] = true;
        dfs(0, hasApple);

        return ans;
    }
};
