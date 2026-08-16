class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<int, int> mp;
        int ans = 0, l = 0;

        for(int r = 0; r < s.length(); r++) {
            mp[s[r]]++;

            while(l < r and mp.size() > 2) {
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
