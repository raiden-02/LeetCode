class Solution {
public:
    int minKnightMoves(int X, int Y) {
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> vis;
        vector<pair<int, int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        q.push({0, 0});
        int lvl = 0;
        X = abs(X), Y = abs(Y);
        vis[{0, 0}] = true;
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                auto cur = q.front(); q.pop();
                int x = cur.first, y = cur.second;
                
                if(x == X and y == Y)
                    return lvl;
                
                for(int i = 0; i < dirs.size(); i++) {
                    int dx = x + dirs[i].first, dy = y + dirs[i].second;
                    
                    if(vis[{dx, dy}] or dx < -2 or dx > X + 2 or dy < -2 or dy > Y + 2) continue;
                    
                    q.push({dx, dy});
                    vis[{dx, dy}] = true;
                }
            }
            
            lvl++;
        }
        
        return -1;
    }
};
