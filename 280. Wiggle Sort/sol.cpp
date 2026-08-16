//intuitive O(nlogn)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return;
        
        sort(nums.begin(), nums.end());
        
        vector<int> tmp = nums;
        
        int mid = n / 2;
        
        if(n % 2) {
        for(int i = 0, j = 0; i <= mid and j < n; i++, j += 2)
            nums[j] = tmp[i];
        
        for(int i = mid + 1, j = 1; i < n and j < n; i++, j += 2)
            nums[j] = tmp[i];
        }
        
        else {
            for(int i = 0, j = 0; i < mid and j < n; i++, j += 2)
            nums[j] = tmp[i];
        
            for(int i = mid, j = 1; i < n and j < n; i++, j += 2)
                nums[j] = tmp[i];
        }
    }
};

//O(n)

// --- alternate solution ---

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            if(i % 2 == 0) {
                if(nums[i] > nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }
            
            else {
                if(nums[i] < nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }
        }
    }
};
