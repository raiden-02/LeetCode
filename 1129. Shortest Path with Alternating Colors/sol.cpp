class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> g(n);
        for(auto &edge : redEdges)
            g[edge[0]].push_back({edge[1], 0});

        for(auto &edge : blueEdges)
            g[edge[0]].push_back({edge[1], 1});

        queue<pair<int, int>> q;
        q.push({0, 0}), q.push({0, 1});
        vector<vector<int>> dist(n, vector<int>(2, -1));
        dist[0][0] = dist[0][1] = 0;

        while(not q.empty()) {
            int s = q.size();

            while(s--) {
                auto cur = q.front(); q.pop();
                int curNode = cur.first, curEdge = cur.second;

                for(auto &neigh : g[curNode]) {
                    int neighNode = neigh.first, neighEdge = neigh.second;

                    if(curEdge == neighEdge or dist[neighNode][neighEdge] != -1) continue;

                    q.push({neighNode, neighEdge});
                    dist[neighNode][neighEdge] = dist[curNode][curEdge] + 1;
                }
            }
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int mn = min(dist[i][0], dist[i][1]);
            int mx = max(dist[i][0], dist[i][1]);
            ans[i] = mn == -1 ? mx : mn;
        }

        return ans;
    }
};
