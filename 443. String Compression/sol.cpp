class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() < 2)
            return chars.size();
        
        int i = 0, j = 0;
        
        while(i < chars.size()) {
            chars[j] = chars[i];
            int c = 0;
            
            while(i < chars.size() and chars[i] == chars[j])
                c++, i++;
            
            if(c == 1)
                j++;
            
            else {
                string t = to_string(c);
                
                for(char c : t)
                    chars[++j] = c;
                
                j++;
            }
        }
        
        return j;
    }
};

// --- alternate solution ---

//extra space intuitive
class Solution {
public:
    int compress(vector<char>& chars) {
        string ans;
        int c = 1;
        char prev = chars[0];
        
        for(int i = 1; i < chars.size(); i++) {
            if(chars[i] == chars[i - 1])
                c++;
            
            else
                ans += (prev + (c == 1 ? "" : to_string(c))), c = 1, prev = chars[i];
        }
        
        ans += (prev + (c == 1 ? "" : to_string(c)));
        
        chars.clear();
        
        for(char x : ans)
            chars.push_back(x);
        
        return chars.size();
    }
};

//no extra space
