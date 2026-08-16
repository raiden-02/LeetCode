class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        array<int, 101> freq = {0};
        int maxm = 0, ans = 0;

        for(int x : nums) {
            freq[x]++;
            maxm = max(maxm, freq[x]);
        }

        for(int i = 1; i <= 100; i++) {
            if(freq[i] == maxm) ans += maxm;
        }

        return ans;
    }
};
