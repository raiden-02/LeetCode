//using graph coloring with two colors

class Solution {
    struct defval {
        int val = -1;
    };
    unordered_map<int, defval> color;
    
    bool bfs(int &start, vector<vector<int>> &graph) {
        queue<int> q;
        color[start].val = 0;
        q.push(start);
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            int curc = color[cur].val;
            for(int &neigh : graph[cur]) {
                if(color[neigh].val == curc) 
                    return false;
                if(color[neigh].val == -1 && color[neigh].val != curc) {
                    color[neigh].val = 1 - curc;
                    q.push(neigh);
                }
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i = 0; i < graph.size(); i++)
            if(color[i].val == -1 && !bfs(i, graph)) return false;
        return true;
    }
};
