class Solution {
    bool ipv4(vector<string> &arr) {
        if(arr.size() != 4) return false;
        
        for(string &x : arr) {
            if((x.length() > 1 and x[0] == '0') or (x.length() > 3)) return false;
            
            for(char y : x)
                if(not isdigit(y)) return false;
            
            int num = stoi(x);
            if(num < 0 or num > 255) return false;
        }
        
        return true;
    }
    
    bool ipv6(vector<string> &arr) {
        if(arr.size() != 8) return false;
        
        for(string &x : arr) {
            if(x.length() < 1 or x.length() > 4) return false;
            
            for(char y : x)
                if(not isxdigit(y)) return false;
        }
        return true;
    }
public:
    string validIPAddress(string IP) {
        if(IP.empty() or IP.back() == '.' or IP.back() == ':')
            return "Neither";
        
        vector<string> arr;
        string cur;
        char prev = '*';
        
        bool f = true;
        
        for(char x : IP) {
            if(x == '.' and prev == x) {f = false; break;}
            
            if(x == '.')
                arr.push_back(cur), cur = "";
            
            else
                cur += x;
            
            prev = x;
        }
        
        arr.push_back(cur);
        if(f and ipv4(arr)) return "IPv4";
        
        arr.clear(), f = true, prev = '*', cur = "";
        
        for(char x : IP) {
            if(x == ':' and prev == x) {f = false; break;}
            
            if(x == ':')
                arr.push_back(cur), cur = "";
            
            else
                cur += x;
            
            prev = x;
        }
        
        arr.push_back(cur);
        if(f and ipv6(arr)) return "IPv6";
        
        return "Neither";
    }
};
