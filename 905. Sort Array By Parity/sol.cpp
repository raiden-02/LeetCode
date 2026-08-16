class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0, r = nums.size() - 1;
        
        for(int x : nums) {
            if(x % 2 == 0)
                ans[l++] = x;
            else
                ans[r--] = x;
        }
        
        return ans;
    }
};
