class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> mp;
        int s = 0, n = nums.size(), ans = 0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(x > sum) return -1;
        
        if(x == sum) return n;
        
        x = sum - x;
        
        for(int i = 0; i < n; i++) {
            s += nums[i];
            
            if(s == x)
                ans = i + 1;
            
            if(mp.find(s - x) != mp.end())
                ans = max(ans, i - mp[s - x]);
            
            if(mp.find(s) == mp.end())
                mp[s] = i;
        }
        
        return n - ans == n ? -1 : n - ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int r = 0, l = 0, n = nums.size();
        int s = 0, maxm = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum == x) return n;
        int req = sum - x;

        while(r < n) {
            s += nums[r];

            while(l < r && s > req) {
                s -= nums[l++];
            }

            if(s == req) maxm = max(maxm, r - l + 1);

            r++;
        }

        return maxm == 0 ? -1 : n - maxm;
    }
};
