class Solution {
    vector<string> prefixes(string const& s) {
        vector<string> ans;
        
        for(int i = 0; i < s.length(); i++) {
            string tmp = s.substr(i);
            
            int l = 0, r = tmp.length() - 1;
            
            for(; l < r and tmp[l] == tmp[r]; l++, r--);
            
            if(l < r) continue;
            
            ans.push_back(s.substr(0, i));
        }
        
        return ans;
    }
    
    vector<string> suffixes(string const& s) {
        vector<string> ans;
        
        for(int i = 0; i < s.length(); i++) {
            string tmp = s.substr(0, i + 1);
            
            int l = 0, r = tmp.length() - 1;
            
            for(; l < r and tmp[l] == tmp[r]; l++, r--);
            
            if(l < r) continue;
            
            ans.push_back(s.substr(i + 1));
        }
        
        return ans;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> ans;
        
        for(int i = 0; i < words.size(); i++)
            mp[words[i]] = i;
        
        for(int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            
            if(mp.find(rev) != mp.end() and mp[rev] != i)
                ans.push_back({mp[rev], i});
            
            for(string &prefix : prefixes(words[i])) {
                reverse(prefix.begin(), prefix.end());
                
                if(mp.find(prefix) != mp.end())
                    ans.push_back({i, mp[prefix]});
            }
            
            for(string &suffix : suffixes(words[i])) {
                reverse(suffix.begin(), suffix.end());
                
                if(mp.find(suffix) != mp.end())
                    ans.push_back({mp[suffix], i});
            }
        }
        
        return ans;
    }
};
