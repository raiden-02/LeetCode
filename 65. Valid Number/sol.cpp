class Solution {
public:
    bool isNumber(string const& s) {
        int i = 0;
        
        for(; s[i] == ' '; i++);
        
        if(s[i] == '+' or s[i] == '-') i++;
        
        int nums = 0, point = 0;
        
        for(; isdigit(s[i]) or s[i] == '.'; i++)
            s[i] == '.' ? point++ : nums++;
        
        if(nums < 1 or point > 1)
            return false;
        
        if(s[i] == 'e' or s[i] == 'E') {
            i++;
            
            if(s[i] == '+' or s[i] == '-') i++;;
            
            nums = 0;
            
            for(; isdigit(s[i]); i++, nums++);
            
            if(nums < 1)
                return false;
        }
        
        for(; i < s.length() and s[i] == ' '; i++);
        
        return i == s.length();
    }
};
