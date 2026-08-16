class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        int i = 0;
        string t = "!?',;. ";
        unordered_set<char> trash(t.begin(), t.end());
        unordered_set<string> ban(banned.begin(), banned.end());
        
        while(i < paragraph.length()) {
            while(i < paragraph.length() and trash.find(paragraph[i]) != trash.end()) i++;
            
            string s;
            
            while(i < paragraph.length() and trash.find(paragraph[i]) == trash.end())
                s += paragraph[i], i++;
            
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            
            mp[s]++;
        }
        
        string ans;
        int mc = 0;
        
        for(auto &x : mp) {
            if(x.first != "" and ban.find(x.first) == ban.end() and x.second > mc)
                ans = x.first, mc = x.second;
        }
        
        return ans;
    }
};
