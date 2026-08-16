class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), prev;
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] == prev) continue;
            int tar = nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int s = nums[l] + nums[r];
                if(s > -tar)
                    r -= 1;
                else if(s < -tar)
                    l += 1;
                else {
                    vector<int> tmp = {nums[i], nums[l], nums[r]};
                    ans.insert(tmp);
                    l += 1;
                    r -= 1;
                }
            }
            prev = nums[i];
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
