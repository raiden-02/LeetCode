class Solution {
    vector<vector<int>> ans;
    vector<bool> vis;
    vector<int> path;
    int n;
    
    void dfs(vector<vector<int>> &graph, int cur) {
        vis[cur] = true;
        path.push_back(cur);
        
        if(cur == n - 1)
            ans.push_back(path);
        
        for(int &neigh : graph[cur]) {
            if(not vis[neigh])
                dfs(graph, neigh);
        }
        
        vis[cur] = false;
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vis.resize(n, false);
        
        dfs(graph, 0);
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    vector<vector<int>> ans;
    int n;
    vector<bool> vis;

    void dfs(vector<vector<int>> &g, vector<int> &tmp, int cur) {
        tmp.push_back(cur);
        vis[cur] = true;

        if(cur == n - 1) {
            ans.push_back(tmp);
        }

        for(int neigh : g[cur]) {
            if(not vis[neigh])
                dfs(g, tmp, neigh);
        }

        vis[cur] = false;
        tmp.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vis.assign(n, false);
        vector<int> tmp;

        dfs(graph, tmp, 0);

        return ans;
    }
};
