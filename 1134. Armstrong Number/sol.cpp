class Solution {
public:
    bool isArmstrong(int n) {
        string s = to_string(n);
        int exp = s.length(), ans = 0;
        
        for(char x : s)
            ans += pow(x - '0', exp);
        
        return ans == n;
    }
};
