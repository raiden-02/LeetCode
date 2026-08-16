class Solution {
    vector<int> ans;
    
    bool helper(string &s, int ind, vector<int> &cac) {
        if(ind >= s.length() and cac.size() >= 3) {
            ans = cac;
            return true;
        }
        
        long cur = 0;
        bool f = false;
        
        for(int i = ind; i < s.length(); i++) {
            cur = cur * 10 + s[i] - '0';
            
            if(cur > INT_MAX or (s[ind] == '0' and i > ind))
                return false;
            
            if(cac.size() < 2 or (long)cac.back() + (long)cac[cac.size() - 2] == cur) {
                cac.push_back(cur);
                
                f = f or helper(s, i + 1, cac);
            
                cac.pop_back();
            }
        }
        
        return f;
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> cac;
        helper(num, 0, cac);
        return ans;
    }
};
