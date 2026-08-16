class Solution {
    public String addBinary(String a, String b) {
        int carry = 0, i = a.length() - 1, j = b.length() - 1;
        StringBuilder ans = new StringBuilder();
        
        while(i >= 0 || j >= 0) {
            int n1 = 0, n2 = 0;
            
            if(i >= 0) {
                n1 = a.charAt(i) - '0';
                i--;
            }
            
            if(j >= 0) {
                n2 = b.charAt(j) - '0';
                j--;
            }
            
            if(carry + n1 + n2 == 3) {
                carry = 1;
                ans.append('1');
            }
            
            else if(carry + n1 + n2 == 2) {
                carry = 1;
                ans.append('0');
            }
            
            else if(carry + n1 + n2 == 1) {
                carry = 0;
                ans.append('1');
            }
            
            else {
                carry = 0;
                ans.append('0');
            }
        }
        
        if(carry != 0)
            ans.append('1');
        
        ans.reverse();
        return ans.toString();
    }
}
