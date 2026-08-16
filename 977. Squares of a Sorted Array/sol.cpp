class Solution {
    vector<int> squared(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) nums[i] *= nums[i];
        return nums;
    }
    
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), t = 0;
        vector<int> ans(n);
        
        int ind = lower_bound(nums.begin(), nums.end(), 0) - nums.begin(), l, r;
        
        if(ind >= n) {
            reverse(nums.begin(), nums.end());
            return squared(nums);
        }
        
        if(nums[ind] == 0)
            ans[t++] = 0, l = ind - 1, r = ind + 1;
        
        else
            l = ind - 1, r = ind;
        
        while(l < r and l >= 0 and r < n) {
            if(abs(nums[r]) < abs(nums[l]))
                ans[t++] = nums[r++];
            else
                ans[t++] = nums[l--];
        }
        
        while(l >= 0)
            ans[t++] = nums[l--];
        
        while(r < n)
            ans[t++] = nums[r++];
        
        return squared(ans); 
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ind = r;
        vector<int> ans(r + 1);
        
        while(l <= r) {
            int a = nums[l] * nums[l], b = nums[r] * nums[r];
            
            if(a >= b)
                ans[ind--] = a, l++;
            
            else
                ans[ind--] = b, r--;
        }
        
        return ans;
    }
};
