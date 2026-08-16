//Prims algo priority queue

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = points.size();
        vector<vector<pair<int, int>>> g(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                g[i].push_back({j, dist}), g[j].push_back({i, dist});
                
            }
        }
        
        vector<bool> vis(n, false);
        int ans = 0;
        pq.push({0, 0});
        
        while(not pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int node = cur.second;
            
            if(vis[node]) continue;
            
            ans += cur.first;
            vis[node] = true;
            
            for(auto &neigh : g[node]) {
                if(not vis[neigh.first])
                    pq.push({neigh.second, neigh.first});
            }
        }
        
        return ans;
    }
};
