class Solution {
    void mergeSort(vector<int> &nums, int l, int r) {
        if(l >= r) return;

        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        
        vector<int> tmp(r - l + 1);
        int ind = 0, i = l, j = mid + 1;

        for(; i <= mid and j <= r; ) {
            if(nums[i] < nums[j]) tmp[ind++] = nums[i++];
            else tmp[ind++] = nums[j++];
        }

        for(; i <= mid; i++) tmp[ind++] = nums[i];
        for(; j <= r; j++) tmp[ind++] = nums[j];

        for(int i = l; i <= r; i++) nums[i] = tmp[i - l];

    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
