class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastInd(26), ans;
        
        for(int i = 0; i < s.length(); i++)
            lastInd[s[i] - 'a'] = i;
        
        for(int i = 0; i < s.length();) {
            int curend = lastInd[s[i] - 'a'];
            int j = i;
            
            for(; j < curend; j++)
                curend = max(curend, lastInd[s[j] - 'a']);
            
            ans.push_back(j - i + 1);
            i = j + 1;
        }
        
        return ans;
    }
};
