class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        const int m = maze.size(), n = maze[0].size();
        const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        
        vector<vector<int>> dist(m, vector<int>(n, -1));
        dist[start[0]][start[1]] = 0;
        
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            
            for(auto const& dir : dirs) {
                int x = cur.first, y = cur.second;
                int len = dist[x][y];
                
                while (x + dir.first >= 0 && x + dir.first < m && y + dir.second >= 0 && y + dir.second < n && !maze[x + dir.first][y + dir.second])
                    x += dir.first,  y += dir.second, len++;

                if (dist[x][y] == -1 || len < dist[x][y]) {
                    dist[x][y] = len;
                    q.push({x, y});
                }
            }                                                                   
        }
        
        return dist[destination[0]][destination[1]];
    }
};
