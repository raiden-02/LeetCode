class Solution {
    vector<vector<int>> ans;
    
    void helper(vector<int> &nums, int ind) {
        if(ind >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i = ind; i < nums.size(); i++) {
            swap(nums[i], nums[ind]);
            helper(nums, ind + 1);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }
};
