class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        vector<int> tmp = nums;
        
        int j = 0;
        
        for(int i = 0; i < n and j < n; i += 2, j++)
            nums[i] = tmp[j];
        for(int i = 1; i < n and j < n; i += 2, j++)
            nums[i] = tmp[j];
        
        tmp = nums;
        int pos = -1;
        
        for(int i = 0; i < n - 1; i++)
            if(nums[i] == nums[i + 1]) {
                pos = i;
                break;
            }
        
        for(int i = 0; i < n; i++) nums[i] = tmp[(i + pos + 1) % n]; 
    }
};
