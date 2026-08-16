class Solution {
public:
    int reverse(int x) {
        long n = abs(x), ans = 0;
        bool f = false;
        if(x < 0)
            f = true;
        
        while(n) {
            int r = n % 10;
            if(ans * 10 > INT_MAX)
                return 0;
            ans = ans * 10 + r;
            n /= 10;
        }
        
        return f ? -ans : ans;
    }
};
