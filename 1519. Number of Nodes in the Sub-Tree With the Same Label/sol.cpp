class Solution {
    vector<vector<int>> g;
    vector<int> ans;
public:
    vector<int> dfs(int cur, int par, string const& labels) {
        vector<int> cnt(26);
        cnt[labels[cur] - 'a'] = 1;

        for (int neigh : g[cur]) {
            if (neigh == par) continue;
            
            vector<int> ccnt = dfs(neigh, cur, labels);
            
            for (int i = 0; i < 26; i++)
                cnt[i] += ccnt[i];
        }

        ans[cur] = cnt[labels[cur] - 'a'];
        return cnt;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string & labels) {
        g.resize(n), ans.resize(n);
        for (auto& edge : edges)
            g[edge[0]].push_back(edge[1]), g[edge[1]].push_back(edge[0]);

        dfs(0, -1, labels);
        return ans;
    }
};
