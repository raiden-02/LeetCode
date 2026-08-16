class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int constexpr MAXM = 1e6 + 1;
        int n = nums.size();
        vector<int> arr(n, MAXM);
        int l = 0, r = n - 1;

        for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if(nums[i] < pivot) arr[l++] = nums[i];
            if(nums[j] > pivot) arr[r--] = nums[j];
        }

        for(int x : nums) {
            if(x == pivot) arr[l++] = x;
        }

        return arr;
    }
};
