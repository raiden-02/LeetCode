class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        
        for(int i = 1; i < n + 1; i++)
            prefix[i] = nums[i - 1] + prefix[i - 1];
        
        for(int i = 1; i < n + 1; i++) {
            if(prefix[i - 1] == prefix[n] - prefix[i])
                return i - 1;
        }
        
        return -1;
    }
};
