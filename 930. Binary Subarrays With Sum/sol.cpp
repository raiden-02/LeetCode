class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int s = 0, ans = 0;
        unordered_map<int, int> mp;

        for(int x : nums) {
            s += x;

            if(s == goal) ans++;

            if(mp.find(s - goal) != mp.end()) {
                ans += mp[s - goal];
            }

            mp[s]++;
        }

        return ans;
    }
};
