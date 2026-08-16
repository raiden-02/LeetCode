class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<vector<int>> ans;
        int cnt = 0, len = 0;
        
        for(int i = m  - 1; i >= 0; i--) {
            int a = num1[i] - '0', carry = 0;
            vector<int> tmp(cnt, 0);
            
            for(int j = n - 1; j >= 0; j--) {
                int prod = ((num2[j] - '0') * a) + carry;
                
                carry = prod / 10;
                int rem = prod % 10;
                
                tmp.insert(tmp.begin(), rem);
            }
            
            while(carry) tmp.insert(tmp.begin(), carry % 10), carry /= 10;
            
            cnt++;
            ans.push_back(tmp);
            len = max(len, (int)tmp.size());
        }
        
        for(auto &x : ans) {
            int t = x.size();
            
            while(t < len)
                x.insert(x.begin(), 0), t++;
        }
        
        string ret;
        int carry = 0;
        int lr = ans.size();
        
        for(int j = len - 1; j >= 0; j--) {
            int s = 0;
            
            for(int i = 0; i < lr; i++) {
                s += ans[i][j];
            }
            
            s += carry;
            
            int rem = s % 10;
            carry = s / 10;
            
            ret = to_string(rem) + ret;
        }
        
        if(carry) ret = to_string(carry) + ret;
        
        while(ret.length() > 1 and ret[0] == '0') ret.erase(ret.begin());
        
        return ret;
    }
};

// --- alternate solution ---

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size() + num2.size());
        
        for(int i = num1.size() - 1; i >= 0; i--) {
            for(int j = num2.size() - 1; j >= 0; j--) {
                int a = ans[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');
                int carry = a / 10;
                ans[i + j + 1] = a % 10;
                ans[i + j] += carry;
            }
        }
        
        int i = 0;
        string out;
        
        while(i < ans.size() && ans[i] == 0) i++;
        
        for(; i < ans.size(); i++)
            out += (char)(ans[i] + '0');
        
        return out == "" ? "0" : out;
    }
};
