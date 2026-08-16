class Solution {
    int partition(vector<int> &nums, int l, int r, int mid) {
        int pivot = nums[mid];
        swap(nums[mid], nums[r]);
        
        for(int i = l; i < r; i++)
            if(nums[i] < pivot)
                swap(nums[i], nums[l++]);
        
        swap(nums[l], nums[r]);
        return l;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), r = n - 1;
        
        while(l <= r) {
            int mid = (l + r) >> 1;
            int p = partition(nums, l, r, mid);
            
            if(p > n - k)
                r = p - 1;
            
            else if(p < n - k)
                l = p + 1;
            
            else
                return nums[p];
        }
        
        return -1;
    }
};
