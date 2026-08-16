class Solution {
    long helper(queue<char> &q) {
        char sign = '+';
        long prev = 0, sum = 0, num = 0;
        
        while(not q.empty()) {
            char c = q.front(); q.pop();
            
            if(isdigit(c))
                num = num * 10 + c - '0';
            
            else if(c == '(')
                num = helper(q);
            
            else {
                if(sign == '+') {
                    sum += prev;
                    prev = num;
                }
                
                else if(sign == '-') {
                    sum += prev;
                    prev = -num;
                }
                
                else if(sign == '*')
                    prev *= num;
                
                else prev /= num;
                
                if(c == ')') break;
                
                num = 0;
                sign = c;
            }
        }
        
        return prev + sum;
    }
public:
    int calculate(string s) {
        queue<char> q;
        
        for(char x : s) if(x != ' ') q.push(x);
        q.push(' ');
        
        return helper(q);
    }
};
