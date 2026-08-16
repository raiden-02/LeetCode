class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, s = 0;
        
        for(int &x : nums) {
            s += x;
            s = max(s, x);
            ans = max(s, ans);
        }
        
        return ans;
    }
};
