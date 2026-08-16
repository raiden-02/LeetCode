class Solution {
    int findquad(int i, int j) {
        if(i <= 2) {
            if(j <= 2)
                return 0;
            
            if(j <= 5)
                return 1;
            
            if(j <= 8)
                return 2;
        }
        
        else if(i <= 5) {
            if(j <= 2)
                return 3;
            
            if(j <= 5)
                return 4;
            
            if(j <= 8)
                return 5;
        }
        
        else if(i <= 8) {
            if(j <= 2)
                return 6;
            
            if(j <= 5)
                return 7;
            
            if(j <= 8)
                return 8;
        }
        
        return -1;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> quadrant(9);
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.size(); j++) {
                if(board[i][j] == '.') continue;
                
                char x = board[i][j];
                
                if(row[i].find(x) != row[i].end())
                    return false;
                row[i].insert(x);
                
                if(col[j].find(x) != col[j].end())
                    return false;
                col[j].insert(x);
                
                int quad = findquad(i, j);
                
                if(quadrant[quad].find(x) != quadrant[quad].end())
                    return false;
                quadrant[quad].insert(x);
            }
        }
        
        return true;
    }
};
