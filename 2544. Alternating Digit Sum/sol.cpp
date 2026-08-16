class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0, exp = 0;
        
        while(n) {
            int rem = n % 10;
            n /= 10;
            ans += pow(-1, exp) * rem;
            exp = (exp + 1) % 2;
        }

        return ans * pow(-1, ++exp);
    }
};
