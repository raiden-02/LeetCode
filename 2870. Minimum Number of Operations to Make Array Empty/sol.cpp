class Solution {
    int helper(int num) {
        int maxThrees = num / 3;

        for (int i = maxThrees; i >= 0; i--) {
            int rem = num - i * 3;
            if (rem % 2 == 0) {
                return i + (rem / 2);
            }
        }
        return -1;  
    }

public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for(int x : nums) {
            freq[x]++;
        }
        
        int n = freq.size();
        int ans = 0;
        
        for(auto [k, v] : freq) {
            int cnt = helper(v);
            
            if(cnt != -1) {
                ans += cnt;
                n--;
            }
        }
        
        return n == 0 ? ans : -1;
    }
};
