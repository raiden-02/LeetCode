class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0, 1}}; // contiguous sum -> freq
        int s = 0, ans = 0;
        
        for(int &x : nums) {
            s += x;
            
            if(mp.find(s - k) != mp.end())
                ans += mp[s - k];
            
            mp[s]++;
        }
        
        return ans;
    }
};
