class Solution {
public:
    double myPow(double x, long long n) {
        if(n < 0)
            n = -n, x = 1 / x;
        
        double ans = 1;
        
        for(long long i = n; i > 0; i /= 2)
            ans = i % 2 ? ans * x : ans, x *= x;
        
        return ans;
    }
};
