class Solution {
    vector<int> parent, rank;
    vector<vector<int>> g;
    map<int, vector<int>> val2node;

    int find(int cur) {
        return cur == parent[cur] ? parent[cur] : parent[cur] = find(parent[cur]);
    }

    void merge(int a, int b) {
        int pa = find(a), pb = find(b);

        if(pa == pb) return;

        if(rank[pa] > rank[pb])
            parent[pb] = pa;
        else if(rank[pb] > rank[pa])
            parent[pa] = pb;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    } 
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), ans = 0;
        g.resize(n), parent.resize(n), rank.resize(n);
        unordered_map<int, int> group;

        for(int i = 0; i < n; i++) parent[i] = i;

        for(auto &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; i++) val2node[vals[i]].push_back(i);

        for(auto &[val, nodes] : val2node) {
            for(int node : nodes) {
                for(int neigh : g[node]) {
                    if(vals[node] >= vals[neigh]) {
                        merge(node, neigh);
                    }
                }
            }

            group.clear();
            for(int node : nodes) {
                group[find(node)]++;
            }

            for(auto &[_, val] : group)
                ans += (val * (val + 1) / 2); //fwd path == bwd path, hence only take possible no of pairs
        }

        return ans;
    }
};
