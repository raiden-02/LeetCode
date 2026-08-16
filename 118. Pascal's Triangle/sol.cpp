class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        
        vector<vector<int>> ans(numRows);
        ans[0] = {1}, ans[1] = {1, 1};
        
        for(int i = 2; i < numRows; i++) {
            vector<int> row(i + 1);
            row[0] = 1, row[i] = 1;
            
            for(int j = 1; j < i; j++)
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            
            ans[i] = row;
        }
        
        return ans;
    }
};
