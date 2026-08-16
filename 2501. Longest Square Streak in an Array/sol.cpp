class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for(int x : nums) {
            float sq = sqrt(x);
            int isq = floor(sq);
            
            if(sq != isq)
                mp[x] = 1;
            
            else if(mp.count(isq))
                mp[x] = mp[isq] + 1;
            
            else mp[x] = 1;
            
            ans = max(ans, mp[x]);
        }
        
        return ans <= 1 ? -1 : ans;
    }
};
