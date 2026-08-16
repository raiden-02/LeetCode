class Solution {
    vector<string> ans;
    
    void helper(string const& s, int ind, string cur, int div) {
        if(div > 4)
            return;
        
        if(ind >= s.length()) {
            if(div != 4) return;
            
            cur.pop_back();
            ans.push_back(cur);
            return;
        }
        
        string tmp;
        char prev = '*';
        
        for(int i = ind; i < s.length(); i++) {
            
            if(tmp.empty() && s[i] == '0') {
                helper(s, i + 1, cur + "0.", div + 1);
                return;
            }
            
            tmp += s[i];
            
            if(stoi(tmp) <= 255)
                helper(s, i + 1, cur + tmp + ".", div + 1);
            
            else
                return;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        helper(s, 0, "", 0);
        return ans;
    }
};
