class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> cap, vow;
        unordered_set<string> wordset(wordlist.begin(), wordlist.end());
        string vowels = "aeiou";
        
        auto vowmask = [&](string &w) {
            for(char &c : w) {
                if(vowels.find(tolower(c)) != string::npos)
                    c = '.';
                else
                    c = toupper(c);
            };
            return w;
        };
        
        for(string &x : wordlist) {
            string w = x;
            transform(w.begin(), w.end(), w.begin(), ::toupper);
            if(cap.find(w) == cap.end())
                cap[w] = x;
            
            w = x;
            w = vowmask(w);
            if(vow.find(w) == vow.end())
                vow[w] = x;
        }
        
        vector<string> ans(queries.size());
        
        for(int i = 0; i < queries.size(); i++) {
            string cur = queries[i], t = queries[i];
            
            if(wordset.find(cur) != wordset.end()) {
                ans[i] = cur;
                continue;
            }
            
            transform(t.begin(), t.end(), t.begin(), ::toupper);
            if(cap.find(t) != cap.end())
                ans[i] = cap[t];
            
            else {
                string k = vowmask(cur);
                if(vow.find(k) != vow.end())
                    ans[i] = vow[k];
            }   
        }
        
        return ans;
    }
};
