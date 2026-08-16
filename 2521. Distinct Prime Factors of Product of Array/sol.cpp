class Solution {
    unordered_set<int> st;
    
    void getPrimes(int num) {
        int x = 2;
        
        while(num > 1) {
            if(num % x == 0)
                st.insert(x), num /= x;
            else x++;
        }
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        for(int x : nums)
            getPrimes(x);
        
        return st.size();
    }
};
