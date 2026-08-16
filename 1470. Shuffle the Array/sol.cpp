class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int s = 2 * n;
        vector<int> ans(s);
        int l = 0, r = n;

        for(int i = 0; i < s; i++)
            ans[i] = i % 2 ? nums[r++] : nums[l++];

        return ans;
    }
};
