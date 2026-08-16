class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(begin(price), end(price));
        int n = price.size(), l = 0, r = price[n - 1] - price[0];

        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            int ind = 0, len = 1;

            for(int i = 1; i < price.size(); i++) {
                if(price[i] - price[ind] >= mid)
                    ind = i, len++;
            }

            if(len >= k)
                l = mid;
            else
                r = mid - 1;
        }

        return l;
    }
};
