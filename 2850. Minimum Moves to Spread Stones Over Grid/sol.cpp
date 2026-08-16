class Solution {
    bool terminating(vector<vector<int>> const& grid) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(grid[i][j] > 1) return false;
            }
        }

        return true;
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        if(terminating(grid)) return 0;

        int ans = numeric_limits<int>::max();

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(grid[i][j] == 0) {
                    grid[i][j] = 1;

                    for(int r = 0; r < 3; r++) {
                        for(int c = 0; c < 3; c++) {
                            if(grid[r][c] > 1) {
                                grid[r][c]--;
                                ans = min(ans, abs(r - i) + abs(c - j) + minimumMoves(grid));
                                grid[r][c]++;
                            }
                        }
                    }

                    grid[i][j] = 0;
                }
            }
        }

        return ans;
    }
};
