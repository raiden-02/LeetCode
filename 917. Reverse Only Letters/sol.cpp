class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ans = s;
        int l = 0, n = s.length(), r = n - 1;
        
        while(l < n and r >= 0) {
            if(isalpha(s[l]) and isalpha(s[r]))
                ans[l] = s[r], l++, r--;
            
            else if(isalpha(s[l]))
                r--;
            
            else if(isalpha(s[r]))
                l++;
            
            else l++, r--;
        }
        
        return ans;
    }
};
