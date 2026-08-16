class Solution {
    pair<int, int> findFarthest(unordered_map<int, vector<int>> &g, int node) {
        queue<int> q;
        q.push(node);
        int dist = 0;
        vector<bool> vis(g.size());
        vector<int> tmp;
        
        while(!q.empty()) {
            int s = q.size();
            tmp = {};
            
            while(s--) {
                int cur = q.front(); q.pop();
                vis[cur] = true;
                tmp.push_back(cur);
                
                for(int &neigh : g[cur]) {
                    if(vis[neigh]) continue;
                    
                    q.push(neigh);
                }
            }
            
            dist++;
        }
        
        return {tmp[0], dist};
    }
public:
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        
        for(auto &x : edges)
            g[x[0]].push_back(x[1]), g[x[1]].push_back(x[0]);
        
        auto f1 = findFarthest(g, 0);
        
        //return 0;
        return findFarthest(g, f1.first).second - 1;
    }
};
