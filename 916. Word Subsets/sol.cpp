class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> maxfreq(26);
        
        for(string &a : B) {
            vector<int> tmp(26);
            for(char c : a) {
                tmp[c - 'a']++;
                maxfreq[c - 'a'] = max(maxfreq[c - 'a'], tmp[c - 'a']);
            }
        }
        
        vector<string> ans;
        
        for(string &a : A) {
            vector<int> tmp(26);
            
            for(char c : a)
                tmp[c - 'a']++;
            
            bool f = true;
            for(int i = 0; i < 26; i++) {
                if(tmp[i] < maxfreq[i]) {
                    f = false;
                    break;
                }
            }
            
            if(f)
                ans.push_back(a);
        }
        
        return ans;
    }
};
