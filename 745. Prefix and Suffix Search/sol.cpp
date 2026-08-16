class WordFilter {
    unordered_map<string, int> mp;
public:
    WordFilter(vector<string>& words) {
        for(int ind = 0; ind < words.size(); ind++) {
            string x = words[ind], y = words[ind];
            reverse(y.begin(), y.end());
            int n = x.length();
            
            for(int i = 1; i < n + 1; i++)
                for(int j = 1; j < n + 1; j++)
                    mp[x.substr(0, i) + ":" + y.substr(0, j)] = ind;
        }
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        string cur = prefix + ":" + suffix;
        
        if(mp.find(cur) != mp.end())
            return mp[cur];
        
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
