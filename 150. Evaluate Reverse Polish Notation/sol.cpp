class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for(string &x : tokens) {
            if(x == "+" or x == "-" or x == "*" or x == "/") {
                long long second = st.top(); st.pop();
                long long first = st.top(); st.pop();

                if(x == "/")
                    st.push(first / second);

                else if(x == "*")
                    st.push(first * second);
                
                else if(x == "-")
                    st.push(first - second);
                
                else
                    st.push(first + second);
            }

            else
                st.push(stoll(x));
        }

        return st.top();
    }
};

// --- alternate solution ---

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(string &x : tokens) {
            if(x.length() == 1 and not isdigit(x[0])) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if(x[0] == '+')
                    st.push(a +  b);
                
                if(x[0] == '-')
                    st.push(a - b);
                
                if(x[0] == '*')
                    st.push(a * b);
                
                if(x[0] == '/')
                    st.push(a / b);
            }
            
            else
                st.push(stoi(x));
        }
        
        return st.top();
    }
};
