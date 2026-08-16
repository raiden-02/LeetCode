class Solution {
    vector<vector<bool>> vis;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    pair<int, int> roll(vector<vector<int>> const& maze, int x, int y, int dx, int dy) {
        while(x + dx >= 0 && x + dx < maze.size() && y + dy >= 0 && y + dy < maze[0].size() && maze[x + dx][y + dy] != 1) {
            x += dx;
            y += dy;
        }
        
        return {x, y};
    }
    
    bool dfs(vector<vector<int>> const& maze, int x, int y, int const& gx, int const& gy) {
        if(vis[x][y]) return false;
        
        if(x == gx && y == gy) return true;
        
        vis[x][y] = true;
        
        for(auto &dir : dirs) {
            auto p = roll(maze, x, y, dir.first, dir.second);
            if(dfs(maze, p.first, p.second, gx, gy))
                return true;
        }
        
        return false;
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vis.resize(maze.size(), vector<bool>(maze[0].size()));
        
        return dfs(maze, start[0], start[1], destination[0], destination[1]);
    }
};
