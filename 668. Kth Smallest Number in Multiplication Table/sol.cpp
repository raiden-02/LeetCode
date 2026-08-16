class Solution {
    //returns the no of numbers less than num
    int helper(int num, int const& m, int const& n) {
        int c = 0;
        
        for(int i = 1; i <= m; i++)
            c += min((num - 1) / i, n);
        /*from m = 3, n = 5, k = 5 then
        1 2 3 4 5 => 4 numbers < 5 = (5 - 1) / 1
        2 4 6 8 10 => 2 numbers < 5 = (5 - 1) / 2
        3 6 9 12 15 => 1 number < 5 = (5 - 1) / 3
        */
        
        return c;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        k--;
        
        while(left < right) {
            int mid = (left + right + 1) >> 1; //including the right bound
            
            if(helper(mid, m, n) > k) //if no of numbers less than mid is greater than k then k mid is obviously not the kth smallest number
                right = mid - 1;
            
            else
                left = mid;
        }
        
        return left;
    }
};
