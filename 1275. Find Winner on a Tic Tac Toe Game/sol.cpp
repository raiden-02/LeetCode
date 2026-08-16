class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid(3, vector<int>(3));
        int n = moves.size();
        
        for(int i = 0; i < n; i++) {
            int x = moves[i][0], y = moves[i][1], c = 0;
            int player = i % 2 == 0 ? 1 : -1;
            grid[x][y] = player;
            string ans = player == 1 ? "A" : "B";
            
            for(int col = 0; col < 3; col++) if(grid[x][col] == player) c++;
            if(c == 3) return ans;
            
            c = 0;
            for(int row = 0; row < 3; row++) if(grid[row][y] == player) c++;
            if(c == 3) return ans;
            
            c = 0;
            for(int row = 0, col = 0; row < 3 and col < 3; row++, col++) if(grid[row][col] == player) c++;
            if(c == 3) return ans;
            
            c = 0;
            for(int row = 0, col = 2; row < 3 and col >= 0; row++, col--) if(grid[row][col] == player) c++;
            if(c == 3) return ans;
        }
        
        return n >= 9 ? "Draw" : "Pending";
    }
};
