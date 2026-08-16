/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            int g = guess(mid);
            
            if(g == -1)
                r = mid - 1;
            else if(g == 1)
                l = mid + 1;
            else
                return mid;
        }
        
        return l;
    }
};
