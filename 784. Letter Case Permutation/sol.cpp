class Solution {
    unordered_set<string> ans;
    void helper(string S, int ind, vector<unordered_map<string, bool>> &mp) {
        if(ind == S.length()) {
            ans.insert(S);
            return;
        }
        
        if(mp[ind][S])
            return;
        
        for(int i = ind; i < S.length(); i++) {
            helper(S, i + 1, mp);
            if(isalpha(S[i])) {
                if(islower(S[i]))
                    S[i] = toupper(S[i]);
                else 
                    S[i] = tolower(S[i]);
                helper(S, i + 1, mp);
            }
        }
        mp[ind][S] = true;
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<unordered_map<string, bool>> mp(S.length());
        helper(S, 0, mp);
        return vector<string>(ans.begin(), ans.end());
    }
};
