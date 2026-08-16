class Solution {
    unordered_map<int, vector<int>> g;
    unordered_map<int, int> indeg;
    unordered_map<int, bool> vis;
    vector<int> ans;

    void dfs(int node) {
        for(int neigh : g[node]) {
            if(!vis[neigh]) {
                ans.push_back(neigh);
                vis[neigh] = true;
                dfs(neigh);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto &x : adjacentPairs) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
            indeg[x[0]]++;
            indeg[x[1]]++;
        }

        vector<pair<int, int>> arr;
        for(auto &[k, v] : indeg) arr.push_back({v, k});

        sort(arr.begin(), arr.end());

        for(auto &x : arr) {
            if(!vis[x.second]) {
                vis[x.second] = true;
                ans.push_back(x.second);
                dfs(x.second);
            }
        }

        return ans;      
    }
};
