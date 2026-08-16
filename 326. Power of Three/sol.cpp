//mathematical log
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1)
            return false;
        
        double a = log10(n) / log10(3);
        
        return a == (int)a;
    }
};

//loop

// --- alternate solution ---

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1)
            return false;
        
        while(n % 3 == 0)
            n /= 3;
        
        return n == 1;
    }
};
