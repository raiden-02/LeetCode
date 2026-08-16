class Solution {
    vector<vector<int>> dp;
    
    int helper(int x, int y, vector<int> const& arr, int const& n) {
        if(y == n - 1) //reached last column
            return 0;
        
        if(arr[y] - 1 == x) //if cur element has obstacle
            return INT_MAX / 2;
        
        if(dp[x][y] != -1)
            return dp[x][y];
        
        if(arr[y + 1] - 1 != x) //if element in same row next column doesnt have obstacle
            return dp[x][y] = helper(x, y + 1, arr, n);
        
        int a, b; //same col jumps
        if(x == 0)
            a = 1, b = 2;
        if(x == 1)
            a = 0, b = 2;
        if(x == 2)
            a = 0, b = 1;
        
        return dp[x][y] = 1 + min(helper(a, y, arr, n), helper(b, y, arr, n));
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        dp.resize(3, vector<int>(n, -1));
        
        return helper(1, 0, obstacles, n);
    }
};

// --- alternate solution ---

class Solution {
    vector<vector<int>> dp;
    
    int helper(int x, int y, vector<int> const& obstacles) {
        if(x == obstacles.size() - 1)
            return 0;
        
        if(obstacles[x] - 1 == y)
            return INT_MAX / 2;
        
        if(dp[x][y] != -1)
            return dp[x][y];
        
        if(obstacles[x + 1] - 1 != y)
            return dp[x][y] = helper(x + 1, y, obstacles);
        
        return dp[x][y] = 1 + min(helper(x, (y + 1) % 3, obstacles), helper(x, (y + 2) % 3, obstacles));
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        dp.resize(obstacles.size(), vector<int>(3, -1));
        
        return helper(0, 1, obstacles);
    }
};
