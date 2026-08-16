class Solution {
public:
    string encode(int num) {
        string ans;
        
        while(num > 2) {
            num % 2 ? ans = "0" + ans : ans = "1" + ans;
            num = (num - 1) / 2;
        }
        
        if(not num) return ans;
        if(num == 1) return "0" + ans;
        return "1" + ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    string encode(int num) {
        string ans = bitset<32>(num + 1).to_string();
        return ans.substr(ans.find('1') + 1);
    }
};
