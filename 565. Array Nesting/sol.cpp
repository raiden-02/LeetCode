class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; i++) {
            int j = i, k = 0;
            
            while(not vis[j]) {
                vis[j] = true;
                k++;
                j = nums[j];
            }
            
            ans = max(ans, k);
        }
        
        return ans;
    }
};
