class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int bucket[n + 1];
        memset(bucket, 0, sizeof(bucket));
        
        for(int &x : nums) {
            if(x >= n) bucket[n]++;
            else bucket[x]++;
        }
        
        for(int i = n; i >= 1; i--) {
            if(bucket[i] == i) return i;
            bucket[i - 1] += bucket[i];
        }
        
        return -1;
    }
};
