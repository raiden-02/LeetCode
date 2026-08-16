class Solution {
public:
    int lastRemaining(int n) {
        int start = 1, rem = n, f = true, skip = 1;
        
        while(rem > 1) {
            if(f or rem % 2)
                start += skip;
            
            skip *= 2;
            rem /= 2;
            f = not f;
        }
        
        return start;
    }
};
