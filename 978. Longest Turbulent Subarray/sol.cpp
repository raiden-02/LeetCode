//intuitive memoization linear time top down dp
class Solution {
    vector<vector<vector<int>>> dp;
    //swt true implies previous one was a greater comparision, otherwise lesser
    int helper(vector<int> const& nums, int ind, bool swt, bool start) {
        if(ind >= nums.size())
            return 0;
        
        if(dp[ind][swt][start] != -1)
            return dp[ind][swt][start];
        
        if(start)
            return dp[ind][swt][start] = 1 + max(helper(nums, ind + 1, true, false), helper(nums, ind + 1, false, false));
        
        if(swt && nums[ind] > nums[ind - 1])
            return dp[ind][swt][start] = 1 + helper(nums, ind + 1, false, false);
        
        if(!swt && nums[ind] < nums[ind - 1])
            return dp[ind][swt][start] = 1 + helper(nums, ind + 1, true, false);
        
        return dp[ind][swt][start] = 0;
    }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 0, n = arr.size();
        
        dp.resize(n, vector<vector<int>>(2, vector<int>(2, -1)));
        
        for(int i = 0; i < n; i++)
            ans = max(ans, helper(arr, i, false, true));
        
        return ans;
    }
};

//linear time bottom up dp

// --- alternate solution ---

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1, n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i - 1])
                dp[i][1] = 1 + dp[i - 1][0];
            
            else if(arr[i] < arr[i - 1])
                dp[i][0] = 1 + dp[i - 1][1];
            
            ans = max(ans, max(dp[i][1], dp[i][0]));
        }
        
        return ans;
    }
};
