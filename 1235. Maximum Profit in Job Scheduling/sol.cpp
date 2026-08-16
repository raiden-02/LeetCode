class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> esp(n);
        
        for(int i = 0; i < n; i++) esp[i] = {endTime[i], startTime[i], profit[i]};
        
        map<int, int> dp = {{0, 0}};
        sort(esp.begin(), esp.end());
        
        for(auto &x : esp) {
            int cur = prev(dp.upper_bound(x[1]))->second + x[2];
            
            if(cur > dp.rbegin()->second)
                dp[x[0]] = cur;
        }
        
        return dp.rbegin()->second;
    }
};
