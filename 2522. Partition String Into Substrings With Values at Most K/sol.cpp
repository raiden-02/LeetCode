class Solution {
    vector<int> dp;
    
    int helper(string const& s, int const& k, int ind) {
        if(ind >= s.length())
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int ans = INT_MAX / 2;
        string t;
        
        for(int i = ind; i < s.length(); i++) {
            t += s[i];
            long long nt = stoll(t);
            
            if(nt > k) break;
            
            ans = min(ans, helper(s, k, i + 1) + 1);
        }
        
        return dp[ind] = ans;
    }
public:
    int minimumPartition(string s, int k) {
        dp.assign(s.length(), -1);
        int ans = helper(s, k, 0);
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};
