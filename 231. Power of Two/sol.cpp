class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        
        while(n > 2 && n % 2 == 0) {
            n /= 2;
        }

        return n == 2;
    }
};

// --- alternate solution ---

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long x = n;
        return (x & (-x)) == x;
    }
};
