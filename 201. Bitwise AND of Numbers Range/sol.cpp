//intuitive
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        
        int c = 0, ans = left & right;
        //cout << ans << endl;
        
        for(long i = left + 1; i < right; i++) {
            ans &= i;
            if(ans == 0) c++;
            
            if(c > 1) break;
        }
        
        return c > 1 ? 0 : ans; 
    }
};

// --- alternate solution ---

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right)
            right = right & (right - 1); //make leftmost bit to 0 each time
        
        return right;
    }
};
