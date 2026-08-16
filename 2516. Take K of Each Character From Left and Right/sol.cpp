class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        for(char x : s)
            mp[x]++;
        
        int n = s.length(), cnt = 0;
        unordered_map<char, int> smp;
        int l = 0, r = 0, ans = -1;
        
        while(r < n) {
            smp[s[r]]++;
            cnt++;
            r++;
            
            while(l <= r and (smp['a'] > mp['a'] - k or smp['b'] > mp['b'] - k or smp['c'] > mp['c'] - k)) {
                smp[s[l]]--;
                l++;
                cnt--;
            }
            
            if(mp['a'] - smp['a'] >= k and mp['b'] - smp['b'] >= k and mp['c'] - smp['c'] >= k)
                ans = max(cnt, ans);
        }
        
        return ans == -1 ? -1 : n - ans;
    }
};
