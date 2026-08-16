class Solution {
    const static int N = 1e5 + 1;
    long long dp[N];
    map<int, int> startTime2Ind;

    long long helper(vector<vector<int>> const& rides, int ind) {
        if(ind >= rides.size())
            return 0;
        
        if(dp[ind] != -1) return dp[ind];

        long long skip = helper(rides, ind + 1);
        long long select = rides[ind][1] - rides[ind][0] + rides[ind][2];
        
        auto it = startTime2Ind.lower_bound(rides[ind][1]);
        if(it == startTime2Ind.end()) return dp[ind] = max(skip, select);

        int nextind = it->second;

        return dp[ind] = max(skip, helper(rides, nextind) + select);
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());

        for(int i = rides.size() - 1; i >= 0; i--)
            startTime2Ind[rides[i][0]] = i;

        memset(dp, -1, sizeof(dp));
        return helper(rides, 0);
    }
};
