class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high - low + 1) / 2;
        return (low % 2 && high % 2) ? ans + 1 : ans;
    }
};
