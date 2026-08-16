class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, diff = INT_MAX;
        int n = nums.size();
        
        int prev = nums[0] - 1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == prev) continue;
            int cur = nums[i], l = i + 1, r = n - 1;
            
            while(l < r) {
                int s = cur + nums[l] + nums[r];
                int d = abs(target - s);
                
                if(d < diff)
                    diff = d, ans = s;
                
                if(s > target)
                    r--;
                
                else if(s < target)
                    l++;
                
                else
                    break;
            }
            prev = nums[i];
        }
        
        return ans;
    }
};
