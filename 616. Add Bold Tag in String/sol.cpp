//two pointers
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        if(dict.empty())
            return s;
        
        int n = s.length(), start = 0, end = -1;
        string ans;
        
        for(int i = 0; i < n; i++) {
            for(string &x : dict)
                if(x.length() <= n - i and x == s.substr(i, x.length()))
                    end = max(end, (int)(i + x.length() - 1));
            
            if(i <= end) continue;
            
            if(end - start >= 0)
                ans += ("<b>" + s.substr(start, end - start + 1) + "</b>");
                
            ans += s[i], start = i + 1;
        }
        
        ans = start <= end ? ans + ("<b>" + s.substr(start, end - start + 1) + "</b>") : ans;
        
        return ans;
    }
};

//bool array

// --- alternate solution ---

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.length(), r = 0;
        vector<int> mark(n);
        
        for(int i = 0; i < n; i++) {
            for(string &x : dict) {
                if(x == s.substr(i, x.length()))
                    r = max(r, (int)(i + x.length()));
            }
            mark[i] = i < r;
        }
        
        string ans;
        
        for(int i = 0; i < n; i++) {
            if(mark[i] and (i == 0 or not mark[i - 1]))
                ans += "<b>";
            
            ans += s[i];
            
            if(mark[i] and (i == n - 1 or not mark[i + 1]))
                ans += "</b>";
        }
        
        return ans;
    }
};
