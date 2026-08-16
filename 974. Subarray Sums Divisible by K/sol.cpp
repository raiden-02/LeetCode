class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0, s = 0;

        for(int x : nums) {
            s = (s + x) % k;
            if(s < 0) s += k;

            if(mp.count(s))
                ans += mp[s];
            
            mp[s]++;
        }

        return ans;
    }
};
