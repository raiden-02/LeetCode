class Solution {
    unordered_map<int, int> dp;
public:
    int integerReplacement(int n) {
        if(n == 1)
            return 0;
        
        if(dp.find(n) != dp.end())
            return dp[n];
        
        if(n % 2 == 0)
            return dp[n] = integerReplacement(n / 2) + 1;
        
        return dp[n] = min(integerReplacement(n / 2), integerReplacement(n / 2 + 1)) + 2; //to avoid overflow we are directly doing (n / 2) + 1 instead of n + 1 then n / 2 therefore adding two steps directly, same for n - 1 then n / 2 by replacgin it with n / 2 directly which is an integer division equivalent to  (n - 1) / 2
    }
};
