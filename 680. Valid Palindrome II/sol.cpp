class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        
        for(; l <= r and s[l] == s[r]; l++, r--);
        
        if(l > r) return true;
        
        bool f1 = false, f2 = false;
        int left1 = l + 1, right1 = r, left2 = l, right2 = r - 1;
        
        for(; left1 <= right1 and s[left1] == s[right1]; left1++, right1--);
        f1 = left1 > right1;
        
        for(; left2 <= right2 and s[left2] == s[right2]; left2++, right2--);
        f2 = left2 > right2;
        
        return f1 or f2;
    }
};
