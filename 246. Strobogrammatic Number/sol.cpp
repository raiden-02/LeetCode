class Solution {
public:
    bool isStrobogrammatic(string num) {
        for(char x : num) {
            if(x == '2' || x == '5' || x == '3' || x == '7' || x == '4')
                return false;
        }
        
        string prev = num;
        for(int i = 0; i < num.length(); i++) {
            if(num[i] == '6')
                num[i] = '9';
            else if(num[i] == '9')
                num[i] = '6';
        }
        
        reverse(num.begin(), num.end());
        return prev == num;
    }
};
