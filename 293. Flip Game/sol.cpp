class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        if(s.length() <= 1)
            return {};
        
        vector<string> ans;
        
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == '+' and s[i] == s[i + 1]) {
                s[i] = '-', s[i + 1] = '-';
                ans.push_back(s);
                s[i] = '+', s[i + 1] = '+';
            }
        }
        
        return ans;
    }
};
