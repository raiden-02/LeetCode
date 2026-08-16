class Solution {
    bool isSub(string const& a, string const& b) {
        int i = 0, j = 0;
        
        while(i < a.length() and j < b.length()) {
            if(a[i] == b[j])
                j++;
            i++;
        }
        
        return j == b.length();
    }
public:
    int findLUSlength(vector<string>& strs) {
        auto comp = [](string &a, string &b) {
            return a.length() > b.length();
        };
        
        sort(strs.begin(), strs.end(), comp);
        
        unordered_map<string, int> mp;
        
        for(string &x : strs)
            mp[x]++;
        
        for(int i = 0; i < strs.size(); i++) {
            string cur = strs[i];
            
            if(mp[cur] != 1) continue;
            
            else if(i != 0 or (i == 0 and i + 1 < strs.size() and cur != strs[i + 1])) {
                string lprev = "";
                bool f = true;
                
                for(int j = 0; j < i and strs[j].length() > cur.length(); j++) {
                    string lcur = strs[j];
                    if(lcur == lprev) continue;
                    
                    if(isSub(lcur, cur)) {
                        f = false;
                        break;
                    }
                    
                    lprev = lcur;
                }
                
                if(f) 
                    return cur.length();
            }
        }
        
        return -1;
    }
};
