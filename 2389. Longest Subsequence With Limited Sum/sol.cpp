class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(queries.size());
        int ind = 0;
        sort(nums.begin(), nums.end());

        for(int tot : queries) {
            int r = n - 1;
            int sum = s;

            while(r >= 0) {
                if(sum <= tot)
                    break;
                
                else
                    sum -= nums[r], r--;
            }

            ans[ind++] = r + 1;
        }

        return ans;
    }
};
