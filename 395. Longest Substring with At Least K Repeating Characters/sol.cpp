class Solution {
public:
    int longestSubstring(string s, int k) {
        int l = 0, r = 0, n = s.length();
        
        unordered_set<char> st(s.begin(), s.end());
        int nset = st.size(), ans = 0;
        unordered_map<char, int> mp;
        unordered_map<char, bool> isgek;

        for(int i = 1; i <= nset; i++) {
            int l = 0, r = 0;
            mp.clear(), isgek.clear();

            while(r < n) {
                mp[s[r]]++;

                if(mp[s[r]] >= k) isgek[s[r]] = true;
                else isgek.erase(s[r]);

                r++;

                if(mp.size() == i and isgek.size() == i) {
                    ans = max(ans, r - l + 1);
                }

                while(l <= r and mp.size() > i) {
                    mp[s[l]]--;
                    if(mp[s[l]] < k)
                        isgek.erase(s[l]);

                    if(mp[s[l]] == 0)
                        mp.erase(s[l]);
                    
                    l++;
                }
            }
        }

        return ans == 0 ? 0 : ans - 1;
    }
};
