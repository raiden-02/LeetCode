class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            if(not dq.empty() and dq.front() == i - k) //out of range
                dq.pop_front();
            
            while(not dq.empty() and nums[dq.back()] < nums[i]) //popping all lesser elements as we only need max element of window
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k - 1) //if size is valid
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};
