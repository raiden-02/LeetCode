class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.length() > t.length())
            return isOneEditDistance(t, s);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != t[i])
                if(s.length() == t.length())
                    return s.substr(i + 1) == t.substr(i + 1);
                else
                    return s.substr(i) == t.substr(i + 1);
        }
        return s.length() == t.length() - 1;
    }
};
