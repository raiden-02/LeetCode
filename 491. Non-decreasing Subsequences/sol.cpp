class Solution {
    set<vector<int>> ans;

    void helper(vector<int> &nums, int ind, vector<int> &tmp) {
        if(ind >= nums.size()) {
            if((int)tmp.size() >= 2) ans.insert(tmp);
            return;
        }

        helper(nums, ind + 1, tmp);

        if(tmp.empty() or tmp.back() <= nums[ind]) {
            tmp.push_back(nums[ind]);
            helper(nums, ind + 1, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tmp;

        helper(nums, 0, tmp);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
