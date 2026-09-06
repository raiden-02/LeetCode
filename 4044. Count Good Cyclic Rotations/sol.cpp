class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        // 123456123456
        const int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) nums.push_back(nums[i]);
        
        vector<long long> prefixsum(2 * n);
        prefixsum[0] = nums[0];
        for (int i = 1; i < 2 * n; i++) prefixsum[i] = prefixsum[i - 1] + nums[i];
        
        for (int i = 0; i < n; i++) {
            int start = i;
            int end = i + n - 1;
            int mid = i + n / 2;

            long long first_sum = i - 1 >= 0 ? 
                prefixsum[mid - 1] - prefixsum[i - 1] : prefixsum[mid - 1];

            long long second_sum = prefixsum[end] - prefixsum[mid - 1];
            // cout << start << " " << mid - 1 << " " << mid << " " << end << endl;
            // cout << first_sum << " " << second_sum << endl << endl;

            if (first_sum > second_sum) ans++;
        }

        return ans;
    }
};
