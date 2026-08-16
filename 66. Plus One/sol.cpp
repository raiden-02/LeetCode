class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            int cur = carry + digits[i];
            
            if(i == n - 1)
                cur++;
            
            if(cur == digits[i]) break;
            
            carry = cur / 10;
            digits[i] = cur % 10;
        }
        
        if(carry) digits.insert(digits.begin(), carry);
        
        return digits;
    }
};
