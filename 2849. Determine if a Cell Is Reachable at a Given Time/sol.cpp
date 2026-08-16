class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diff =  max(abs(fx - sx), abs(fy - sy));
        return diff > 0 ? diff <= t : t != 1;
    }
};
