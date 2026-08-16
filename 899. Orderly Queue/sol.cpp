class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            char c = *min_element(s.begin(),s.end());
            vector<int> inds;
            
            for(int i = 0; i < s.length(); i++) if(s[i] == c) inds.push_back(i);
            
            string ans = s;
            
            for(int ind : inds)
                ans = min(ans, s.substr(ind) + s.substr(0, ind));
            
            return ans;
        }
        
        sort(s.begin(), s.end());
        return s;
    }
};
