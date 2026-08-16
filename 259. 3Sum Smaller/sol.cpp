class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3)
            return 0;
        unordered_map<int, int> mp;
        int ans = 0;
        mp[nums[0] + nums[1]] += 1;
        for(int i = 2; i < n; i++) {
            for(auto &x : mp) {
                if(x.first + nums[i] < target)
                    ans += x.second;
            }
            for(int j = 0; j < i; j++) //loop inside to guarantee that the new index added is not in the pair of indices in key
                mp[nums[i] + nums[j]] += 1;
        }
        return ans;
    }
};
