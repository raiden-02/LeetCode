#define ll long long

class Solution {
    bool check(string &s) {
       for(int i = 0, j = s.length() - 1; i <= j; i++, j--) 
           if(s[i] != s[j]) 
               return false;
        
        return true;
    }
public:
    int superpalindromesInRange(string left, string right) {
        vector<ll> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        for(int i = 1; i <= 8000; i++) {
            string l = to_string(i),  r = l; 
            reverse(r.begin(), r.end());
            
            arr.push_back(stoll(l+r));
            
            for(int d = 0; d < 10; d++)
                arr.push_back(stoll(l + to_string(d) + r));
        }
        
        ll l = stoll(left), r = stoll(right);
        
        int ans = 0;
        
        for(ll i : arr) {
            if(i > r)
                break;
            
            i *= i;
            
            string k = to_string(i);
            if(i >= l &&  i <= r && check(k))
                ans++;
        }
        
        return ans;
        
    }
};
