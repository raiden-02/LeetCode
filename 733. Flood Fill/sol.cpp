class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<vector<bool>> vis(m, vector<bool>(n));
        vis[sr][sc] = true;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        
        while(not q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur.first, y = cur.second;

            for(auto &dir : dirs) {
                int dx = x + dir.first, dy = y + dir.second;

                if(dx >= 0 and dx < m and dy >= 0 and dy < n and not vis[dx][dy] and image[dx][dy] == color)
                    q.push({dx, dy}), vis[dx][dy] = true, image[dx][dy] = newColor;
            }
        }
        
        return image;
    }
};
