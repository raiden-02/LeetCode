class Solution {
    int dp[1000][1000];
    
    int helper(vector<int> const& stones, int start, int end, int s) {
        if(start >= end || s <= 0)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        return dp[start][end] = max(s - stones[start] - helper(stones, start + 1, end, s - stones[start]), s - stones[end] - helper(stones, start, end - 1, s - stones[end])); //min max strategy works as follows for alice's difference to be max sum - selecion - next guys score should be max => bobs score implicitly will return minimum, hence maxmin criteria is satisfied
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int s = accumulate(stones.begin(), stones.end(), 0);
        
        memset(dp, -1, sizeof(dp));
        
        return helper(stones, 0, stones.size() - 1, s);   
    }
};
