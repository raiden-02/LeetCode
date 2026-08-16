class Solution {
public:
    string lastSubstring(string s) {
        int maxc = *max_element(s.begin(), s.end());
        vector<int> indices;
        int n = s.length();
        
        for(int i = 0; i < s.length(); i++)
            if(s[i] == maxc)
                indices.push_back(i);
        
        int offset = 1;
        
        while(indices.size() > 1) {
            char curmax = 'a';
            for(int &i : indices)
                curmax = max(curmax, i + offset < n ? s[i + offset] : 'a');
            
            vector<int> nextind;
            
            for(int i = 0; i < indices.size(); i++) {
                if(i > 0 && indices[i - 1] + offset == indices[i])
                    continue;
                
                if(indices[i] + offset < n && s[indices[i] + offset] == curmax)
                    nextind.push_back(indices[i]);
            }
            
            indices = nextind;
            offset++;
        }
        
        return s.substr(indices.back());
    }
};
