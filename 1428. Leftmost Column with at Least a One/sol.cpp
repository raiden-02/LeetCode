/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int m = dim[0], n = dim[1], ans = n;
        
        for(int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            
            while(l < r) {
                int mid = (l + r) >> 1;
                
                if(binaryMatrix.get(i, mid) == 0)
                    l = mid + 1;
                else
                    r = mid;
            }
            
            if(l < n and binaryMatrix.get(i, l)) ans = min(ans, l);
        }
        
        return ans == n ? -1 : ans;
    }
};
