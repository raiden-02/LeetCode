class Solution {
    public boolean judgeSquareSum(int c) {
        long l = 0, h = (long)Math.sqrt(c);
        
        while(l <= h) {
           long prod = l * l + h * h;
            
            if(prod == c) return true;
            
            else if(prod < c) l++;
            else h--;
        }
        
        return false;
    }
}
