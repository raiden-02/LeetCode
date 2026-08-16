class Solution {
    int helper(int x, int y) {
        if(x % y == 0)
            return y;
        return helper(y, x % y);
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x + y)
            return false;
        
        return x == z || y == z || z % helper(x, y)  == 0;
    }
};
