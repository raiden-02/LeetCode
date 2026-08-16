class Solution {
    public int findComplement(int num) {
        int n = num, mask = 1;
        
        while(n != 0) {
            num = num ^ mask;
            mask <<= 1;
            n >>= 1;
        }
        
        return num;
    }
}
