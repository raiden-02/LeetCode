class Solution {
public:
    int countDigits(int num) {
        int n = num, ans = 0;
        
        while(n) {
            int x = n % 10;
            
            if(num % x == 0) ans++;
            
            n /= 10;
        }
        
        return ans;
    }
};
