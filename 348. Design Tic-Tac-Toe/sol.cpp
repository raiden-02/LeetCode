class TicTacToe {
    vector<vector<int>> grid;
    int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        grid.resize(n, vector<int>(n));
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        grid[row][col] = player;
        
        /*for(auto &x : grid) {
            for(int &y : x)
                cout << y << " ";
            cout << endl;
        }
        
        cout << endl;*/
        
        int r = row, c = col, cnt = 1;
        int left = c, right = c;
        
        //same row
        while(left - 1 >= 0 or right + 1 < n) {
            if(left - 1 >= 0) {
                if(grid[r][left - 1] == player)
                    left--, cnt++;
                else
                    break;
            }
            
            if(right + 1 < n) {
                if(grid[r][right + 1] == player)
                    right++, cnt++;
                else
                    break;
            }
        }
        
        if(cnt == n) return player;
        
        //same col
        cnt = 1;
        left = r, right = r;
        while(left - 1 >= 0 or right + 1 < n) {
            if(left - 1 >= 0) {
                if(grid[left - 1][c] == player)
                    left--, cnt++;
                else
                    break;
            }
            
            if(right + 1 < n) {
                if(grid[right + 1][c] == player)
                    right++, cnt++;
                else
                    break;
            }
        }
        
        if(cnt == n) return player;
        
        //diag
        cnt = 1;
        int dr = r, dc = c, ur = r, uc = c;
        while((ur - 1 >= 0 and uc - 1 >= 0) or (dr + 1 < n and dc + 1 < n)) {
            if(ur - 1 >= 0 and uc - 1 >= 0) {
                if(grid[ur - 1][uc - 1] == player)
                    ur--, uc--, cnt++;
                else
                    break;
            }
            
            if(dr + 1 < n and dc + 1 < n) {
                if(grid[dr + 1][dc + 1] == player)
                    dr++, dc++, cnt++;
                else
                    break;
            }
        }
        
        if(cnt == n) return player;
        
        //anti diag
        cnt = 1;
        dr = r, dc = c, ur = r, uc = c;
        while((ur - 1 >= 0 and uc + 1 < n) or (dr + 1 < n and dc - 1 >= 0)) {
            if(ur - 1 >= 0 and uc + 1 < n) {
                if(grid[ur - 1][uc + 1] == player)
                    ur--, uc++, cnt++;
                else
                    break;
            }
            
            if(dr + 1 < n and dc - 1 >= 0) {
                if(grid[dr + 1][dc - 1] == player)
                    dr++, dc--, cnt++;
                else
                    break;
            }
        }
        
        return cnt == n ? player : 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
