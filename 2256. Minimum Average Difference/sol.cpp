class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long ans = LONG_MAX;
        int ind = -1, n = nums.size();
        
        vector<long> left(n), right(n);
        left[0] = nums[0], right[n - 1] = nums[n - 1];
        
        for(int l = 1, r = n - 2; l < n and r >= 0; l++, r--)
            left[l] = nums[l] + left[l - 1], right[r] = nums[r] + right[r + 1];
        
        for(int i = 0; i < n - 1; i++) {
            long diff = abs(left[i] / (i + 1) - right[i + 1] / (n - i - 1));
            
            if(diff < ans)
                ans = diff, ind = i;
        }
        
        int diff = abs(left[n - 1] / n);
        if(diff < ans)
            ans = diff, ind = n - 1;
        
        return ind;
    }
};
