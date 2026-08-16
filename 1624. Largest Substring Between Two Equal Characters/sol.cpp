class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int mp[26], ans = -1;
        memset(mp, -1, sizeof(mp));

        for(int i = 0; i < s.length(); i++) {
            int x = s[i] - 'a';
            if(mp[x] == -1) mp[x] = i;
            else ans = max(ans, i - mp[x] - 1);
        }

        return ans;
    }
};
