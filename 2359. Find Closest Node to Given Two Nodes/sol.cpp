class Solution {
    vector<int> bfs(vector<int> &edges, int node) {
        queue<int> q;
        q.push(node);
        vector<bool> vis(edges.size(), false);
        vis[node] = true;
        int lvl = 0;
        vector<int> ret(edges.size(), INT_MAX);

        while(not q.empty()) {
            
            int s = q.size();
            while(s--) {
                int cur = q.front(); q.pop();
                ret[cur] = lvl;
                int neigh = edges[cur];

                if(neigh == -1 or vis[neigh]) continue;
                q.push(neigh), vis[neigh] = true;
            }

            lvl++;
        }

        return ret;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> a = bfs(edges, node1), b = bfs(edges, node2);
        int ans = -1, ansd = INT_MAX;

        for(int i = 0; i < edges.size(); i++) {
            int maxd = max(a[i], b[i]);

            if(maxd < ansd) {
                ans = i;
                ansd = maxd;
            }
        }

        return ans;
    }
};
