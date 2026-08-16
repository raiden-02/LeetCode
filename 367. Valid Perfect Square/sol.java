class Solution {
    public boolean isPerfectSquare(int num) {
        long l = 0, r = num;
        
        while(l <= r) {
            long mid = (l + r) >> 1;
            long p = mid * mid;
            
            if(p == num)
                return true;
            
            else if(p < num)
                l = mid + 1;
            
            else
                r = mid - 1;
        }
        
        return false;
    }
}
