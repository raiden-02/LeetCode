class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans = numeric_limits<int>::min();
        int n = nums.size();
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < n; i++) {
            int maxm = 0;

            while(!pq.empty()) {
                if(i - pq.top().second > k) pq.pop();
                else {
                    maxm = pq.top().first; 
                    break;
                }
            }

            maxm = max(maxm + nums[i], nums[i]);
            ans = max(ans, maxm);
            pq.push({maxm, i});
        }

        return ans;
    }
};
