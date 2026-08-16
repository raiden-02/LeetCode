/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     public int get(int index) {}
 * }
 */

class Solution {
    public int search(ArrayReader reader, int target) {
        int l = 0, r = (int)(Math.pow(10, 4));
        
        while(l <= r) {
            int mid = (l + r) >> 1;
            int val = reader.get(mid);
            
            if(val > target)
                r = mid - 1;
            
            else if(val < target)
                l = mid + 1;
            
            else
                return mid;
        }
        
        return -1;
    }
}
