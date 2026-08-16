class Solution {
    unordered_set<string> vis;
    int ans;
    
    void helper(string const& s, int ind) {
        if(ind >= s.length()) {
            ans = max(ans, (int)vis.size());
            return;
        }
        
        string cur;
        
        for(int i = ind; i < s.length(); i++) {
            cur += s[i];
            
            if(vis.find(cur) == vis.end())
                vis.insert(cur), helper(s, i + 1), vis.erase(cur);
        }
    }
public:
    int maxUniqueSplit(string s) {
        ans = 0;
        helper(s, 0);
        return ans;
    }
};
