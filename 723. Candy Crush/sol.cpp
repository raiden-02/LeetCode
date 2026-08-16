class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        bool crush = false;
        
        auto comp = [&](int &a, int &b, int &c) {
            return abs(a) == abs(b) and abs(a) == abs(c);
        };
        
        //horizontal sweep
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n - 2; j++) {
                if(board[i][j] != 0 and comp(board[i][j], board[i][j + 1], board[i][j + 2])) {
                    board[i][j] = board[i][j + 1] = board[i][j + 2] = -abs(board[i][j]); //this is for saving the marking the elems to crush and comparing their abs values to other adjacent elements if there are more than 3 since they will be the same
                    crush = true;
                }
            }
        }
        
        //vertical sweep
        for(int i = 0; i < m - 2; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] != 0 and comp(board[i][j], board[i + 1][j], board[i + 2][j])) {
                    board[i][j] = board[i + 1][j] = board[i + 2][j] = -abs(board[i][j]);
                    crush = true;
                }
            }
        }
        
        //crush and drop down
        for(int j = 0; j < n; j++) {
            int anchor = m - 1;
            
            for(int i = m - 1; i >= 0; i--) {
                if(board[i][j] > 0) {
                    board[anchor][j] = board[i][j];
                    anchor--;
                }
            }
            
            for(int i = 0; i <= anchor; i++) //top elements which go empty after crush
                board[i][j] = 0;
        }
        
        return crush ? candyCrush(board) : board;
    }
};
