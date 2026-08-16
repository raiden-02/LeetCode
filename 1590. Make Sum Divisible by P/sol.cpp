class Solution {
    /*
    say two numbers a, b 
    a = p * q + r1, b = p * q + r2
    
    for a - b to be divisible by p
    r1 - r2 should be divisible by p implies (r1 - r2) % p == 0
    
    to avoid going below zero we do (r1 - r2 + p) % p
    */
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), ans = n;
        unordered_map<int, int> mp = {{0, -1}};
        int tar = 0, s = 0;
        
        for(int &x : nums)
            tar += x, tar %= p;
        
        if(tar == 0)
            return 0;
        
        for(int i = 0; i < n; i++) {
            s += nums[i];
            s %= p;
            
            int comp = (s - tar) % p;
            
            if(comp < 0)
                comp = (comp + p) % p;
            
            if(mp.find(comp) != mp.end())
                ans = min(ans, i - mp[comp]);
            
            mp[s] = i;
        }
        
        return ans == n ? -1 : ans;
    }
};
