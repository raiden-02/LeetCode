class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> g(n);
        vector<vector<bool>> neigh(n, vector<bool>(n, false));

        for(auto &x : roads) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
            neigh[x[0]][x[1]] = neigh[x[1]][x[0]] = true;
        }

        int ans = 0;

        for(int a = 0; a < n; a++) {
            for(int b = a + 1; b < n; b++) {
                ans = max(ans, (int)(g[a].size() + g[b].size() - neigh[a][b]));
            }
        }

        return ans;
    }
};
