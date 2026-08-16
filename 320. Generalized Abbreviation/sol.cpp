class Solution {
    vector<string> ans;
    
    void helper(string &s, int ind, string cur, int len) {
        if(ind >= s.length()) {
            if(len)
                cur += to_string(len);
            
            ans.push_back(cur);
            return;
        }
        
        helper(s, ind + 1, cur, len + 1);
        
        if(len) cur += to_string(len);
        cur += s[ind];
        
        helper(s, ind + 1, cur, 0);
    }
public:
    vector<string> generateAbbreviations(string word) {
        helper(word, 0, "", 0);
        return ans;
    }
};
