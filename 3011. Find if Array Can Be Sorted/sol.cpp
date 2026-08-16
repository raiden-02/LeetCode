class Solution {
    bool bubble_sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    if( __builtin_popcount(arr[j]) == __builtin_popcount(arr[j + 1])) {
                        swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }

                    else return false;
                }
            }
        }

        return true;
    }
public:
    bool canSortArray(vector<int>& nums) {
        return bubble_sort(nums);
    }
};
