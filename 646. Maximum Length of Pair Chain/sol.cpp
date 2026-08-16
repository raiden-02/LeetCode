class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> const& a,vector<int> const& b) { return a[1] < b[1]; });

        int ans = 0, cur = numeric_limits<int>::min();

        for (auto const& x : pairs) {
            if (x[0] > cur) {
                ans++;
                cur = x[1];
            }
        }

        return ans;
    }
};
