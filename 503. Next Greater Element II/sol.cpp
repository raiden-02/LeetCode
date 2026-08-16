//brute force intuitive
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            bool f = true;
            
            for(int j = i + 1; j < n; j++)
                if(nums[j] > nums[i]) {
                    ans.push_back(nums[j]), f = false;
                    break;
                }
            
            for(int j = 0; j < i && f; j++)
                if(nums[j] > nums[i]) {
                    ans.push_back(nums[j]), f = false;
                    break;
                }
            
            if(f)
                ans.push_back(-1);
        }
        
        return ans;
    }
};

//stack

// --- alternate solution ---

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i = n - 1; i >= 0; i--)
            st.push(i);
        
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = -1;
            
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            
            if(!st.empty())
                ans[i] = nums[st.top()];
            
            st.push(i);
        }
        
        return ans;
    }
};
