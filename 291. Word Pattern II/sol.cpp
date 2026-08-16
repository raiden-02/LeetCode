class Solution {
    unordered_map<string, char> m1;
    unordered_map<char, string> m2;
public:
    bool helper(string const& s, string const& t, int si, int ti) {
        if(si == s.length() && ti == t.length())
            return 1;
        if(si >= s.length() || ti >= t.length())
            return 0;

        string cur;
        bool ans = 0;

        for(int i = ti; i < t.length(); i++) {
            cur += t[i];

            if(m1.find(cur) != m1.end() && m2.find(s[si]) != m2.end()) {
                if(m1[cur] == s[si] && m2[s[si]] == cur)
                    ans = ans || helper(s, t, si + 1, i + 1);
            }

            else if(m1.find(cur) == m1.end() && m2.find(s[si]) == m2.end()) {
                m1[cur] = s[si];
                m2[s[si]] = cur;
                ans = ans || helper(s, t, si + 1, i + 1);
                m1.erase(cur);
                m2.erase(s[si]);
            }
        }
        return ans;
    }
    
    bool wordPatternMatch(string pattern, string s) {
        return helper(pattern, s, 0, 0);
    }
};
