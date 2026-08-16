class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        
        for(int x : nums) {
            if(x == 0) return 0;
            else if(x < 0) cnt++;
        }

        return cnt % 2 ? -1 : 1;
    }
};
