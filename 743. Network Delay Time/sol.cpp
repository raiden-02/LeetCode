class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);
        
        for(auto &x : times)
            g[x[0]].push_back({x[1], x[2]});
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> time(n + 1, INT_MAX);
        pq.push({0, k});
        time[k] = 0;
        vector<bool> vis(n + 1);
        
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int node = cur.second, curtime = cur.first;
            vis[node] = true;
            
            for(auto &[neigh, ntime] : g[node]) {
                if(!vis[neigh] && ntime + curtime < time[neigh]) {
                    time[neigh] = ntime + curtime;
                    pq.push({time[neigh], neigh});
                }
            }
        }
        
        int ans = *max_element(time.begin() + 1, time.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
