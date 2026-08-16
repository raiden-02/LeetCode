class Solution {
public:
    int maxVowels(string s, int k) {
        int r = 0, ans = 0, l = 0, cnt = 0;
        unordered_map<char, int> mp;

        while(r < s.length()) {
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                mp[s[r]]++;
                cnt++;
            }

            while(l <= r && r - l + 1 > k) {
                if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
                    mp[s[l]]--;
                    cnt--;
                    if(mp[s[l]] == 0) mp.erase(s[l]);
                }
                l++;
            }

            if(r - l + 1 == k) {
                ans = max(ans, cnt);
            }

            r++;    
        }

        return ans;
    }
};
