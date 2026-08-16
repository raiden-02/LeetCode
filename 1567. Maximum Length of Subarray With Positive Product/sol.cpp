class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int zeros = -1, negs = -1, ans = 0, negc = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                zeros = i;
                negs = -1;
                negc = 0;
            }
            
            else {
                if(nums[i] < 0) {
                    negc++;
                    if(negs == -1)
                        negs = i;
                }
                
                ans = negc % 2 ? max(ans, i - negs) : max(ans, i - zeros);
            }
        }
        
        return ans;
    }
};
