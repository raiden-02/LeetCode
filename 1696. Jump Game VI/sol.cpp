class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        dq.push_back(0);
        
        for(int i = 1; i < nums.size(); i++) {
            if(dq.front() + k < i) dq.pop_front(); //out of range
            
            nums[i] += nums[dq.front()];
            
            while(not dq.empty() and nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        return nums.back();
    }
};
