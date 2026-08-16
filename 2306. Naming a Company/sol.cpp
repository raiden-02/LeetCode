class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> mp[26];
        for(string &x : ideas) {
            mp[x[0] - 'a'].insert(x.substr(1));
        }

        long long ans = 0;

        for(char x = 0; x < 25; x++) {
            for(char y = x + 1; y < 26; y++) {
                long long cnt = 0;
                
                for(string s : mp[x]) {
                    if(!mp[y].count(s)) continue;
                    cnt++;
                }

                ans += 2 * (mp[x].size() - cnt) * (mp[y].size() - cnt);
            }
        }

        return ans;
    }
};
