class Solution {
    vector<vector<int>> ans;
    
    void helper(vector<int> const& nums, int ind, vector<int> &tmp) {
        if(ind >= nums.size()) {
            ans.push_back(tmp);
            return;
        }
        
        tmp.push_back(nums[ind]);
        helper(nums, ind + 1, tmp);
        tmp.pop_back();
        
        helper(nums, ind + 1, tmp);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        helper(nums, 0, tmp);
        return ans;
    }
};
