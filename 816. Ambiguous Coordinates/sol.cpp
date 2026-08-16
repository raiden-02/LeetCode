class Solution {
    /*
    step 1 : divide into two parts comma
    step 2 : divide each part by decimal
    */
    
    vector<string> helper(string s) {
        int n = s.length();
        
        if(n == 1)
            return {s};
        
        if(s[0] == '0') {
            if(s.back() == '0')
                return {};
            
            return {"0." + s.substr(1)};
        }
        
        vector<string> ret = {s};
        
        for(int i = 0; i < n; i++) {
            string t = s.substr(i + 1);
            
            if(t.empty()) break;
            
            if(t.back() == '0') continue;
            
            ret.push_back(s.substr(0, i + 1) + "." + t);
        }
        
        return ret;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1, s.length() - 2);
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            string l = s.substr(0, i + 1), r = s.substr(i + 1);
            
            if(l.empty() or r.empty()) break;
            
            vector<string> left = helper(s.substr(0, i + 1));
            vector<string> right = helper(s.substr(i + 1));
            
            if(left.empty() or right.empty()) continue;
            
            for(int j = 0; j < left.size(); j++)
                for(int k = 0; k < right.size(); k++)
                    ans.push_back("(" + left[j] + ", " + right[k] + ")");
        }
        
        return ans;
    }
};
