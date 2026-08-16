class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long ret = 0;

        for(int i = 0; i < n; i++) {
            long long ans = maxHeights[i];
            int minm = maxHeights[i];
            bool f = true;

            for(int l = i - 1; l >= 0; l--) {
                    minm = min(maxHeights[l], minm);
                    ans += minm;
            }

           // cout << f << endl;

            minm = maxHeights[i];

            for(int r = i + 1; f && r < n; r++) {
                    minm = min(maxHeights[r], minm);
                    ans += minm;
            }

            //cout << ans << f << endl;

            ret = max(ret, ans);
        }

        return ret;
    }
};
