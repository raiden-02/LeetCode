class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int r = n - 2;
        bool bPivot = false;
        int ans = 1;

        while(r >= 0) {
            if(!bPivot) {
                if(nums[r] > nums[r + 1]) {
                    bPivot = true;
                }

                else ans++;
            }
            
            else {
                if(nums[r] > nums[r + 1]) {
                    return -1;
                }
            }

            r--;
        }

        if(bPivot) {
            if(nums[0] >= nums[n - 1]) return ans;
            return -1;
        }

        return 0;
    }
};
