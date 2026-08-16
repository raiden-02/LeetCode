class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int i = 0; i < t.length() && j < s.length(); i++) {
            if(t[i] == s[j])
                j += 1;
        }
        
        return j == s.length();
    }
};
