class Solution {
    vector<int> dp;
    int helper(vector<int> const& arr, vector<int> const& costs, int ind) {
        if(ind >= arr.size())
            return 0;
        
        if(dp[ind])
            return dp[ind];
        
        int a = helper(arr, costs, ind + 1) + costs[0], i = 0;
        
        while(i < arr.size() && arr[i] < arr[ind] + 7) {i++;};
        int b = helper(arr, costs, i) + costs[1];
        
        i = 0;
        while(i < arr.size() && arr[i] < arr[ind] + 30) {i++;};
        int c = helper(arr, costs, i) + costs[2];
        
        return dp[ind] = min(a, min(b, c));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size());
        return helper(days, costs, 0);
    }
};
