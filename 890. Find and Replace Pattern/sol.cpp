class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, int> m1, m2;
        int m = pattern.length();
        vector<string> ans;
        
        for(string &x : words) {
            int n = x.length();
            m1.clear(), m2.clear();
            
            if(m != n) continue;
            
            int i = 0;
            bool f = true;
            
            while(i < n) {
                if(m1.find(x[i]) != m1.end() and m2.find(pattern[i]) != m2.end() and m1[x[i]] == pattern[i] and m2[pattern[i]] == x[i]) {
                    i++;
                    continue;
                }
                
                else if(m1.find(x[i]) == m1.end() and m2.find(pattern[i]) == m2.end()) {
                    m1[x[i]] = pattern[i], m2[pattern[i]] = x[i], i++;
                    continue;
                }
                
                else {
                    f = false;
                    break;
                }
            }
            
            if(f) ans.push_back(x);
        }
        
        return ans;
    }
};
