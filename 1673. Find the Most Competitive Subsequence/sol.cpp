class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(!ans.empty() && ans.back() > nums[i]) { // if last element in ans is greater than the cur nums element, we have an opportunity to replace it
                if(n - i > k - ans.size()) //if there are more numbers than slots available implies we might have better choice
                    ans.pop_back();
                else
                    break;
            }
            if(ans.size() < k) //max of size k
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
