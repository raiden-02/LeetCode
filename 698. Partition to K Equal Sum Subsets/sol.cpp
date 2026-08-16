class Solution {
    vector<bool> vis;
    
    bool helper(vector<int> const& arr, int ind, int s, int const& tot, int div) {
        if(div == 1)
            return true;
        
        if(s == tot)
            return helper(arr, 0, 0, tot, div - 1);
        
        for(int i = ind; i < arr.size(); i++) {
            if(vis[i] or arr[i] + s > tot) continue;
            
            vis[i] = true;
            if(helper(arr, i + 1, s + arr[i], tot, div)) return true;
            vis[i] = false;
        }
        
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        
        if(nums.size() < k or tot % k)
            return false;
        
        tot /= k;
        vis.resize(nums.size(), false);
        
        return helper(nums, 0, 0, tot, k);
    }
};
