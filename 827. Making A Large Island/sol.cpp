class Solution {
    vector<int> parent, area;
    
    int find(int i) {
        return i == parent[i] ? i : parent[i] = find(parent[i]);
    }
    
    void merge(int i, int j) {
        int pi = find(i), pj = find(j);
        
        if(pi == pj) return;
        
        parent[pi] = pj;
        area[pj] += area[pi];
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        
        auto valid = [&](int i, int j) {
            return i >= 0 and i < m and j >= 0 and j < n;
        };
        
        parent.resize(m * n), area.resize(m * n, 1);
        
        for(int i = 0; i < m * n; i++) parent[i] = i;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int key = i * n + j;
                    
                    for(auto &dir : dirs) {
                        int di = i + dir.first, dj = j + dir.second;
                        int dkey = di * n + dj;
                        
                        if(valid(di, dj) and grid[di][dj]) merge(key, dkey);
                    }
                }
            }
        }
        
        int ans = 0;
        for(int x : area) ans = max(ans, x);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    int key = i * n + j;
                    int combarea = 1;
                    unordered_set<int> vis;
                    
                    for(auto &dir : dirs) {
                        int di = i + dir.first, dj = j + dir.second;
                        int dkey = di * n + dj;
                        
                        if(valid(di, dj) and grid[di][dj]) {
                            int par = find(dkey);
                            
                            if(vis.empty() or vis.find(par) == vis.end())
                                combarea += area[par], vis.insert(par);
                        } 
                    }
                    
                    ans = max(ans, combarea);
                }
            }
        }
        
        return ans == 0 ? m * n : ans;
    }
};
