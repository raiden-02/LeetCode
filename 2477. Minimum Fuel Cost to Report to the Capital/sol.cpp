class Solution {
    long long ans = 0;
    unordered_map<int, vector<int>> g;

    long long dfs(int cur, int par, int seats) {
        long long reps = 1;

        for(int neigh : g[cur]) {
            if(neigh != par)
                reps += dfs(neigh, cur, seats);
        }

        if(cur != 0) ans += ceil((double)reps / seats);

        return reps;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        for(auto &x : roads) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        dfs(0, -1, seats);

        return ans;
    }
};
