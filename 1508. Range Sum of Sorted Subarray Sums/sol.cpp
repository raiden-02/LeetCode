class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefix(n + 1);
        int mod = 1e9 + 7;
        
        for(int i = 0; i < n; i++)
            prefix[i + 1] = (prefix[i] + nums[i]) % mod;
        
        int s = n * (n + 1) / 2 + 1, ind = 0;
        vector<int> ans(s - 1);
        
        for(int i = 0; i < n; i++) 
            for(int j = i + 1; j <= n; j++)
                ans[ind++] = (prefix[j] - prefix[i]);
        
        sort(ans.begin(), ans.end());
        int out = 0;
        
        for(int i = left - 1; i < right; i++)
            out = (out + ans[i]) % mod;
        
        return out;
    }
};
