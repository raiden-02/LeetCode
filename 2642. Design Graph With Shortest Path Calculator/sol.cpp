class Solution {
public:
    double maxdistability(int n, vector<vector<int>>& edges, vector<double>& succdist, int start, int end) {
        vector<vector<pair<int, double>>> g(n);

        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succdist[i]});
            g[edges[i][1]].push_back({edges[i][0], succdist[i]});
        }
        
        vector<bool> vis(n, false);
        priority_queue<pair<double, int>> pq;
        pq.push({1, start});
        vector<double> dist(n);
        dist[start] = 1;

        while(!pq.empty()) {
            auto [curdist, curnode] = pq.top(); pq.pop();
            vis[curnode] = true;

            for(auto &[nn, np] : g[curnode]) {
                if(!vis[nn] && dist[nn] < np * curdist) {
                    dist[nn] = np * curdist;
                    pq.push({dist[nn], nn}); 
                }
            }
        }

        return dist[end];
    }
};
*/

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

// --- alternate solution ---

class Graph {
    vector<vector<pair<int, int>>> g;
    const int MAX_INT = numeric_limits<int>::max();
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        g.resize(n);

        for(auto &x : edges) {
            g[x[0]].push_back({x[1], x[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});
        vector<int> dists(n, MAX_INT);
        dists[node1] = 0;

        while(!pq.empty()) {
            auto [curdist, curnode] = pq.top(); pq.pop();
            vis[curnode] = true;

            for(auto &[nn, nd] : g[curnode]) {
                if(!vis[nn] && dists[nn] > nd + curdist) {
                    dists[nn] = nd + curdist;
                    pq.push({dists[nn], nn}); 
                }
            }
        }

        return dists[node2] == MAX_INT ? -1 : dists[node2];
    }
};

/*
