class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> vis(k + 1, false);
        int cnt = 0, ans = 0;
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] >= 1 && nums[i] <= k && !vis[nums[i]]) {
                vis[nums[i]] = true;
                cnt++;
            }
            
            ans++;
            
            if(cnt == k) return ans;
        }
        
        return ans;
    }
};
