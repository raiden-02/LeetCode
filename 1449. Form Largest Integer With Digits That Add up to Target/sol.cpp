class Solution {
    vector<string> dp;
    
    string maxm(string const& a, string const& b) {
        return a.length() > b.length() ? a : b;
    }

    string helper(vector<int> const& cost, int target, int const& n) {
        if(target == 0)
            return "";
        
        if(dp[target] != "-1")
            return dp[target];
        
        string ans;
        
        for(int i = 0; i < n; i++) {
            if(target - cost[i] > 0) {
                string tmp = helper(cost, target - cost[i], n);
                if(!tmp.empty())
                    ans = maxm(ans, to_string(i + 1) + tmp);
            }
            
            else if(target - cost[i] == 0)
                ans = maxm(ans, to_string(i + 1) + helper(cost, target - cost[i], n));
        }
        
        return dp[target] = ans;
    }
public:
    string largestNumber(vector<int>& cost, int target) {
        dp.resize(target + 1, "-1");
        
        string ans = helper(cost, target, cost.size());
        
        return ans.empty() ? "0" : ans;
    }
};
