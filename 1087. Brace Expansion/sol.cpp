class Solution {
    vector<string> ans;
    
    void helper(string const& s, int ind, string cur) {
        if(ind >= s.length()) {
            ans.push_back(cur);
            return;
        }
        
        int end = s[ind] == '{' or s[ind] == '}' ? ind + 1 : ind;
        ind = end;
        
        while(end < s.length() && s[end] != '{' && s[end] != '}')
            end++;
        
        if(end >= s.length()) {
            ans.push_back(cur + s.substr(ind));
            return;
        }
        
        for(int i = ind; i < end; i++) {
            if(s[i] == ',' or s[i] == '{' or s[i] == '}') continue;
            helper(s, end + 1, cur + s[i]);
        }
    }
public:
    vector<string> expand(string s) {
        helper(s, 0, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};
