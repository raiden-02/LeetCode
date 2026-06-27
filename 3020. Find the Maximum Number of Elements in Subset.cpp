class Solution {
    int greatestOddLE(int x) {
        if (x % 2 != 0) return x;
        return x - 1;
    }

public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        int ans = 1;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto [k, v] : mp) {
            if (k == 1) {
                ans = max(ans, greatestOddLE(v));
                continue;
            }

            long long x = k;
            int len = 0;

            while (mp.count(x) && mp[x] >= 2) {
                len += 2;
                x = x * x;
            }

            if (mp.count(x)) {
                // terminal center exists once
                len += 1;
            } else {
                // last pair we added cannot both be used;
                // one of them becomes the center
                len -= 1;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
