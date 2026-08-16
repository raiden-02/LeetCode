class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> grid(numRows);
        int r = 0, add = 1;

        for(char x : s) {
            if(r >= numRows) add = -1, r = (numRows - 2 + numRows) % numRows;
            else if(r < 0) add = 1, r = 1 % numRows;
            grid[r].push_back(x);
            r += add;
        }

        string ans;
        for(int i = 0; i < numRows; i++) for(int j = 0; j < grid[i].size(); j++) ans.push_back(grid[i][j]);

        return ans;
    }
};
