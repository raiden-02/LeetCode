class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> vis(right + 1, true);
        vis[1] = false;
        vector<int> ans(2, -1), primes;
        int mindiff = INT_MAX;

        for(int i = 2; i * i <= right; i++) {
            if(vis[i]) {
                for(int j = i * i; j <= right; j += i) vis[j] = false;
            }
        }

        for(int i = left; i <= right; i++) if(vis[i]) primes.push_back(i);

        for(int i = 0; i < (int)primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];

            if(diff < mindiff) {
                mindiff = diff;
                ans[0] = primes[i], ans[1] = primes[i + 1];
            }
        }

        return ans;
    }
};
