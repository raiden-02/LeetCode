class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.length(), ans = 0, l = 0;
        
        for(int r = 0; r < n; r++) {
            mp[s[r]]++;
            
            while(mp.size() > k) {
                mp[s[l]]--;
                
                if(!mp[s[l]])
                    mp.erase(s[l]);
                
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};
