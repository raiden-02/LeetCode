class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());
        int32_t n = piles.size();
        int32_t ans = 0;
        
        for(int32_t i = 1, cnt = 0; i < n && cnt < n / 3; i += 2, cnt += 1) {
            ans += piles[i];    
        }

        return ans;
    }
};
