class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0;  i < n; i++) {
            int t = i;
            int cnt = 0;
            
            while(t) {
                cnt += t & 1;
                t = t >> 1;
            }
            
            if(cnt == k) ans += nums[i];
        }
        
        return ans;
    }
};
