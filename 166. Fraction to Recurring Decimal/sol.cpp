class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        
        long divd = abs((long)numerator);
        long divs = abs((long)denominator);
        long remainder = divd % divs;
        
        string ans;
        if((long)numerator * denominator < 0)
            ans += '-';
        
        ans += to_string(divd / divs);
        
        if(remainder == 0)
            return ans;
        
        ans += '.';
        unordered_map<long, int> mp;
        
        while(remainder != 0) {
            if(mp.find(remainder) != mp.end()) {
                ans.insert(ans.begin() + mp[remainder], '(');
                ans += ')';
                break;
            }
            mp[remainder] = ans.length();
            remainder *= 10;
            ans += to_string(remainder / divs);
            remainder %= divs;
        }
        
        return ans;
    }
};
