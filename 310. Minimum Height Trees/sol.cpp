class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n);
        unordered_map<int, vector<int>> g;
        for(auto &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
            deg[edge[0]] += 1;
            deg[edge[1]] += 1;
        }
        
        vector<int> lvl;
        queue<int> q;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++) { //pushing all leaves into queue
            if(deg[i] == 1) {
                q.push(i);
                vis[i] = true;
            }
            lvl.push_back(i);
        }
        
        int ans = 0;
        while(!q.empty()) {
            int s = q.size();
            ans += 1;
            lvl = {};
            while(s--) {
                int cur = q.front();
                q.pop();
                //cout << cur << " ";
                lvl.push_back(cur);
                vis[cur] = true;
                for(int &neigh : g[cur]) {
                    if(vis[neigh]) continue;
                    deg[neigh] -= 1;
                    if(deg[neigh] == 1) {
                        q.push(neigh);
                        vis[neigh] = true;
                    }
                }
            }
            //cout << endl;
        }
        return lvl;
    }
};
