class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0)
            return -1;
        
        int ans = 0;
        
        for(int n = 1; n <= k; n++) {
            ans = (ans * 10 + 1) % k;
            
            if(ans == 0)
                return n;
        }
        
        return -1;
    }
};
