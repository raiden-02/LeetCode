class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, i = num1.length() - 1, j = num2.length() - 1;
        string ans;
        
        while(i >= 0 && j >= 0) {
            int a = num1[i] - '0', b = num2[j] - '0';
            
            int cur = a + b + carry;
            carry = cur / 10;
            int rem = cur % 10;
            
            ans = to_string(rem) + ans;
            
            i--, j--;
        }
        
        while(i >= 0) {
            int cur = carry + (num1[i] - '0');
            carry = cur / 10;
            int rem = cur % 10;
            ans = to_string(rem) + ans;
            i--;
        }
        
        while(j >= 0) {
            int cur = carry + (num2[j] - '0');
            carry = cur / 10;
            int rem = cur % 10;
            ans = to_string(rem) + ans;
            j--;
        }
        
        if(carry)
            ans = to_string(carry) + ans;
        
        return ans;
    }
};
