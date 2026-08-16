class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        
        while(Y > X) {
            if(X % 2 == 0)
                X *= 2;
            
            else
                X -= 1;
            
            ans += 1;
        }
        
        return ans + (X - Y);
    }
};
