class Solution {
    int m, n;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool helper(vector<vector<char>> &board, string const& word, int ind, int x, int y) {
        if(ind >= word.length()) return true;

        for(auto &dir : dirs) {
            int dx = dir.first + x, dy = dir.second + y;

            if(dx >= 0 && dx < m && dy >= 0 && dy < n && board[dx][dy] == word[ind]) {
                char x = board[dx][dy];
                board[dx][dy] = '*';
                if(helper(board, word, ind + 1, dx, dy)) return true;
                board[dx][dy] = x;
            }
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(word[0] == board[i][j]) {
                    char x = board[i][j];
                    board[i][j] = '*';
                    if(helper(board, word, 1, i, j)) return true;
                    board[i][j] = x;
                } 
            }
        }

        return false;
    }
};

// --- alternate solution ---

class Solution {
    bool helper(vector<vector<char>> &board, string const& word, int i, int j, int si) {
        if(si == word.length())
            return true;
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[si])
            return false;
        
        //cout << i << " " << j << endl;
        char temp = board[i][j]; 
        board[i][j] = '*';
        bool ans = helper(board, word, i + 1, j, si + 1) || helper(board, word, i - 1, j, si + 1) || helper(board, word, i, j + 1, si + 1) || helper(board, word, i, j - 1, si + 1);
        
        board[i][j] = temp;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++)
                if(word[0] == board[i][j] && helper(board, word, i, j, 0))
                    return true;
        }
        return false;
    }
};
