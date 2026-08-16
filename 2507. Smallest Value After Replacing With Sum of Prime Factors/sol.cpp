class Solution {
    int getPrimeSum(int n) {
        int c = 2, ret = 0;
        
        while(n > 1)
            n % c == 0 ? n /= c, ret += c : c++;
        
        return ret;
    }
public:
    int smallestValue(int n) {
        int prev = -1;
        
        while(n != prev) {
            prev = n;
            n = getPrimeSum(n);
        }
        
        return n;
    }
};
