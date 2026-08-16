class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;
        
        queue<int> q;
        q.push(source);
        vector<vector<int>> g(n);
        vector<bool> vis(n);;
        vis[source] = true;

        for(auto &x : edges)
            g[x[0]].push_back(x[1]), g[x[1]].push_back(x[0]);

        while(not q.empty()) {
            int cur = q.front(); q.pop();

            if(cur == destination)
                return true;
            
            for(int neigh : g[cur]) {
                if(vis[neigh]) continue;

                if(neigh == destination) return true;

                q.push(neigh), vis[neigh] = true;
            }
        }

        return false;
    }
};
