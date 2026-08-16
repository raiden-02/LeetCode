class Solution {
    int ans = 0;
    vector<bool> col;
    vector<string> board;
    
    void helper(int n, int ind) {
        if(n < 0)
            return;
        
        if(ind >= board.size()) {
            if(n == 0) ans++;
            return;
        }
        
        for(int j = 0; j < board.size(); j++) {
            if(ind == 0)
                board[ind][j] = 'Q', col[j] = true, helper(n - 1, ind + 1), board[ind][j] = '.', col[j] = false;
            
            else {
                bool f = true;
                
                if(col[j]) f = false;
                
                if(f) {
                    for(int r = ind - 1, c = j - 1; r >= 0 and c >= 0; r--, c--)
                        if(board[r][c] == 'Q') {
                            f = false;
                            break;
                        }
                }
                
                if(f) {
                    for(int r = ind - 1, c = j + 1; r >= 0 and c < board.size(); r--, c++)
                        if(board[r][c] == 'Q') {
                            f = false;
                            break;
                        }
                }
                
                if(f)
                    board[ind][j] = 'Q', col[j] = true, helper(n - 1, ind + 1), board[ind][j] = '.', col[j] = false;
            }   
        }
    }
public:
    int totalNQueens(int n) {
        board.resize(n, string(n, '.'));
        col.resize(n, false);
        
        helper(n, 0);
        
        return ans;
    }
};
