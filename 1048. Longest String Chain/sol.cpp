class Solution {
    unordered_map<int, unordered_set<string>> mp;
    unordered_map<string, int> dp;
    
    int helper(string &x) {
        if(dp.find(x) != dp.end())
            return dp[x];
        
        int n = x.length();
        int len = n - 1;
        
        int ans = 1;
        
        for(int i = 0; i < n; i++) {
            string s = x.substr(0, i) + x.substr(i + 1);
            
            if(mp[len].find(s) != mp[len].end())
                ans = max(ans, helper(s) + 1);
        }
        
        return dp[x] = ans;
    }
public:
    int longestStrChain(vector<string>& words) {
        for(string &x : words)
            mp[x.length()].insert(x);
        
        int ans = 1;
        
        for(string &x : words)
            ans = max(ans, helper(x));
        
        return ans;
    }
};
