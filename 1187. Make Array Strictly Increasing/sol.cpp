class Solution {
    const int UPPER = 2e3 + 1;

    map<pair<int, int>, int> dp;
    int helper(vector<int> &arr1, vector<int> const& arr2, int i, int prev) {
        if(i >= arr1.size()) return 0;

        if(dp.count({i, prev})) return dp[{i, prev}];

        int ans = UPPER;

        if(arr1[i] > prev)
            ans = helper(arr1, arr2, i + 1, arr1[i]);
        
        int ind = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if(ind < arr2.size())
            ans = min(ans, helper(arr1, arr2, i + 1, arr2[ind]) + 1);

        return dp[{i, prev}] = ans;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int ans = helper(arr1, arr2, 0, -1);

        return ans < UPPER ? ans : -1;
    }
};
