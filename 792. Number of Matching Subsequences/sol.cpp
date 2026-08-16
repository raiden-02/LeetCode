class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mp(26);
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++)
            mp[s[i] - 'a'].push_back(i);
        
        for(string &x : words) {
            int lastInd = -1;
            bool f = true;
            
            for(char c : x) {
                auto it = upper_bound(mp[c - 'a'].begin(), mp[c - 'a'].end(), lastInd); // strictly > than
                
                if(it == mp[c - 'a'].end()) { f = false; break; }
                
                else lastInd = *it;
            }
            
            if(f) ans++;
        }
        
        return ans;
    }
};
