class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int prev = 0, ans = 0;
        unordered_map<char, int> mp;
        
        for(int i = 0; i < keyboard.length(); i++)
            mp[keyboard[i]] = i;
        
        for(char x : word) {
            ans += abs(prev - mp[x]);
            prev = mp[x];
        }
        return ans;
    }
};
