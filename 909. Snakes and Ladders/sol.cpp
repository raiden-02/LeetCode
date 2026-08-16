class Solution {
    int find(vector<vector<int>> const& board, int x) {
        int n = board.size();
        int row = ceil((double)x/n)-1, col;
        if(row&1) {
            col = n-1-(x-1)%n;
        }
        else {
            col = (x-1)%n;
        }
        return board[n-1-row][col];
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m = board.size(), ans = 0, goal = m * m;
        queue<int> q;
        q.push(1);
        vector<bool> vis(goal + 1, false);
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                int cur = q.front(); q.pop();
                if(cur == goal) return ans;
                
                for(int i = 1; i <= 6; i++) {
                    int next = cur + i;
                    if(next > goal) break;
                    
                    int r = ceil((double)next / m) - 1, c;
                    c = r & 1 ? m - 1 - (next - 1) % m : (next - 1) % m;
                    int neigh = board[m - 1 - r][c];
                    
                    neigh = neigh == -1 ? next : neigh;
                    
                    if(vis[neigh]) continue;
                    
                    vis[neigh] = true, q.push(neigh);
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};
