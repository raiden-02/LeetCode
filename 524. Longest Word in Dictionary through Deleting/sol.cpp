class Solution {
    bool helper(string const& x, string &y) {
        int k = 0;
        for(int i = 0; i < x.length() && k < y.length(); i++) {
            if(y[k] == x[i])
                k++;
        }
        
        return k == y.length();
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        auto longest = [&](string &a, string &b) {
            return a.length() > b.length() || (a.length() == b.length() && a < b) ? a : b;
        };
        
        string ans;
        for(string &x : d) {
            if(helper(s, x))
                ans = longest(ans, x);
        }
        
        return ans;
    }
};
