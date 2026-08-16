class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans1 = nums[0] != 0, ans2 = 0;
        
        for(int i = 0; i < n; i++) {
            if((i + 1) > nums[i] && (i + 1 >= n || (i + 1) < nums[i + 1])) ans1++;
        }
        
        return ans1;
    }
};
