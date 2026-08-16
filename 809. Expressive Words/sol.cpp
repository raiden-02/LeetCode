class Solution {
    bool helper(string const& s, string const& word) {
        int i = 0, j = 0;
        while(i < s.length() && j < word.length()) {
            if(s[i] != word[j])
                return false;
            
            int c1 = 1, c2 = 1; i++; j++;
            while(word[j] == word[j - 1]) {
                c2++;
                j++;
            }
            
            while(s[i] == s[i - 1]) {
                c1++;
                i++;
            }

            if(c1 < c2 || (c1 < 3 && c1 != c2))
                return false;
        }
        
        return i == s.length() && j == word.length() ? true : false;
    }
public:
    int expressiveWords(string S, vector<string>& words) {
        if(S.empty() || words.empty())
            return 0;
        
        int ans = 0;
        for(string &word : words) {
            if(helper(S, word))
                ans++;
        }
        
        return ans;
    }
};
