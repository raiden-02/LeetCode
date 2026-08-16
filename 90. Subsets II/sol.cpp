class Solution {
    set<vector<int>> ans;

    void helper(vector<int> const& nums, int ind, vector<int> &tmp) {
        if(ind >= nums.size()) {
            ans.insert(tmp);
            return;
        }
        
        helper(nums, ind + 1, tmp);

        tmp.push_back(nums[ind]);
        helper(nums, ind + 1, tmp);
        tmp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        helper(nums, 0, tmp);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
