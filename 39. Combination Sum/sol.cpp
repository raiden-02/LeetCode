class Solution {
    vector<vector<int>> ans;
    void helper(vector<int> const& arr, int target, int ind, vector<int> &tmp) {
        if(target == 0) {
            ans.push_back(tmp);
            return;
        }
        
        if(target < 0 or ind >= arr.size())
            return;
        
        helper(arr, target, ind + 1, tmp);
        
        int tar = target, cnt = 0;
        
        while(tar - arr[ind] >= 0) {
            tar -= arr[ind];
            tmp.push_back(arr[ind]);
            cnt++;
            helper(arr, tar, ind + 1, tmp);
        }
        
        while(cnt--)
            tmp.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        helper(candidates, target, 0, tmp);
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
    
    void helper(vector<int> const& candidates, int const& target, int ind, int s) {
        if(ind >= candidates.size()) {
            if(target == s)
                ret.push_back(tmp);
            return;
        }
        
        if(s + candidates[ind] <= target) {
            tmp.push_back(candidates[ind]);
            helper(candidates, target, ind, s + candidates[ind]);
            tmp.pop_back();
        }
        
        helper(candidates, target, ind + 1, s);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0, 0);
        return ret;
    }
};
