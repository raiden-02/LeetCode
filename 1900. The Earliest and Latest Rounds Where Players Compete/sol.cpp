class Solution {
    //a & (1 << pos) checks if bit as pos is 1 or not
    //a ^ (1 << pos) makes 0 to 1 or 1 to 0 (in this context we use the latter property to make that guy lose)
    
    int minr = INT_MAX, maxr = INT_MIN;
    
    void dfs(int mask, int round, int i, int j, int const& first, int const& second) {
        if (i >= j)
            dfs(mask, round + 1, 0, 27, first, second);
        
        else if ((mask & (1 << i)) == 0)
            dfs(mask, round, i + 1, j, first, second);
        
        else if ((mask & (1 << j)) == 0)
            dfs(mask, round, i, j - 1, first, second);
        
        else if (i == first && j == second) {
            minr = min(minr, round);
            maxr = max(maxr, round);
        }
        
        else {
            if (i != first && i != second)
                dfs(mask ^ (1 << i), round, i + 1, j - 1, first, second);
            
            if (j != first && j != second)
                dfs(mask ^ (1 << j), round, i + 1, j - 1, first, second);
        }
    }
public:
    vector<int> earliestAndLatest(int n, int first, int second) {
        dfs((1 << n) - 1, 1, 0, 27, first - 1, second - 1);
        
        return {minr, maxr};
    }
};
