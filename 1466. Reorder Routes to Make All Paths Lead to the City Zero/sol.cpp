class Solution {
    int ans = 0;

    void helper(vector<vector<pair<int, int>>> const& g, int cur, int par) {

        for(auto const& [neigh, dir] : g[cur]) {

            //flip the fwd edges
            if(neigh != par) {
                ans += dir;
                helper(g, neigh, cur);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> g(n);

        for(auto &con : connections) {
            g[con[0]].push_back({con[1], 1});
            g[con[1]].push_back({con[0], 0});
        }

        helper(g, 0, -1);

        return ans;
    }
};
