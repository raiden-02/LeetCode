// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long r = n, l = 1;
        
        while(l < r) {
            long mid = (l + r) >> 1;
            
            if(isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        
        return l;
    }
};
