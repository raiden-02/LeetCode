class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastReachable = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--)
            if(nums[i] + i >= lastReachable)
                lastReachable = i;
        return lastReachable == 0;
    }
};
