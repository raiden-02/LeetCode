class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int maxm = *max_element(nums.begin(), nums.end());
        vector<bool> vis(maxm + 1, false);
        vector<int> div(maxm + 1, 0);

        for (int x : nums) vis[x] = true;

        for (int i = 1; i <= maxm; i++) {
            if (!vis[i]) continue;

            for (int j = i; j <= maxm; j += i) {
                if (div[j] == 0) div[j] = i;
            }
        }

        for (int x : nums) ans += div[x];

        return ans;
    }
};
