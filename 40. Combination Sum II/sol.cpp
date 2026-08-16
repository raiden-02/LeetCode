class Solution {
    vector<bool> vis;
    set<vector<int>> seen;
    
    void helper(vector<int> &nums, int ind, int target, vector<int> tmp) {
        if(target == 0) {
            sort(tmp.begin(), tmp.end());
            if(seen.find(tmp) != seen.end())
                return;
            
            seen.insert(tmp);
            return;
        }
        
        if(ind >= nums.size())
            return;
        
        int prev = -1;
        for(int i = ind; i < nums.size(); i++) {
            if(vis[i] or nums[i] == prev) continue;
            
            if(target >= nums[i])
                vis[i] = true, tmp.push_back(nums[i]), helper(nums, i + 1, target - nums[i], tmp), vis[i] = false, tmp.pop_back();
            
            prev = nums[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vis.resize(candidates.size());
        helper(candidates, 0, target, tmp);
        ans.insert(ans.end(), seen.begin(), seen.end());
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    vector<vector<int>> ans;
    set<vector<int>> vis;
    
    void helper(vector<int> const& arr, int ind, int target, vector<int> &tmp) {
        if(target == 0) {
            if(vis.find(tmp) != vis.end()) return;
            vis.insert(tmp);
            ans.push_back(tmp);
            return;
        }
        
        if(ind >= arr.size() or target < 0) return;
        
        int prev = -1;
        
        for(int i = ind; i < arr.size(); i++) {
            if(arr[i] == prev) continue;
            
            if(target - arr[i] >= 0) {
                tmp.push_back(arr[i]);
                helper(arr, i + 1, target - arr[i], tmp);
                tmp.pop_back();
            }
            
            prev = arr[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, tmp);
        return ans;
    }
};
