class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while(l < r) {
            int mid = (l + r)  >> 1;
            int hrs = 0;

            for(int x : piles) {
                hrs += x % mid ? (x / mid) + 1 : x / mid;
            }

            if(hrs > h)
                l = mid + 1;
            else
                r = mid; 
        }

        return l;
    }
};
