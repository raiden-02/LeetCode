class Solution {
    long helper(queue<char> &q) {
        long sum = 0, prev = 0, num = 0;
        char sign = '+';

        while(not q.empty()) {
            char cur = q.front(); q.pop();

            if(isdigit(cur))
                num = num * 10 + (cur - '0');

            else if(cur == '(')
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

                else if(sign == '*') {
                    prev *= num;
                }

                else if(sign == '/') {
                    prev /= num;
                }

                if(cur == ')')
                    break;
                
                sign = cur;
                num = 0;
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
