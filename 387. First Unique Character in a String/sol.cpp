class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26);
        
        for(char x : s)
            mp[x - 'a']++;
        
        for(int i = 0; i < s.length(); i++)
            if(mp[s[i] - 'a'] == 1)
                return i;
        
        return -1;
    }
};
