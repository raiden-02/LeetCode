class Solution {
public:
    string convertToBase7(int num) {
        if(not num) return "0";
        
        int n = abs(num);
        string ans;
        
        while(n)
            ans = to_string(n % 7) + ans, n /= 7;
        
        return num < 0 ? '-' + ans : ans;
    }
};
