class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> sums;
        int ans = 0, mod = 1e9 + 7;
        
        for(auto &x : nums) {
            string sx = to_string(x);
            reverse(sx.begin(), sx.end());
            int rx = stoi(sx);
            
            if(sums.find(x - rx) != sums.end())
                ans = (ans + sums[x - rx]) % mod;
            
            sums[x - rx] = (sums[x - rx] + 1) % mod;
        }
        
        return ans;
    }
};
