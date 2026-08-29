class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted(n);

        for (int i = 0; i < n; i++) {
            sorted[i] = {nums[i], i};
        }

        sort(sorted.begin(), sorted.end());

        vector<int> tv = {sorted[0].first}, ti = {sorted[0].second};

        for (int i = 1; i < n; i++) {
            if (abs(sorted[i - 1].first - sorted[i].first) <= limit) {
                tv.push_back(sorted[i].first);
                ti.push_back(sorted[i].second);
            }

            else {
                sort(ti.begin(), ti.end());
                for (int i = 0; i < ti.size(); i++) {
                    nums[ti[i]] = tv[i];
                }

                ti = {sorted[i].second};
                tv = {sorted[i].first};
            }
        }

        sort(ti.begin(), ti.end());
        for (int i = 0; i < ti.size(); i++) {
            nums[ti[i]] = tv[i];
        }

        return nums;
    }
};
