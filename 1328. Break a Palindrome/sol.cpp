class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size(), i = 0;
        if(n == 1) return "";
        
        unordered_map<char, int> mp;
        for(char x : palindrome) mp[x]++;
        bool f = false;
        
        auto erase = [&mp](char x) {
            mp[x]--;
            
            if(mp[x] == 0) mp.erase(x);
        };
        
        for(; i < n; i++) {
            if(palindrome[i] == 'a') continue;
            
            else {
                char x = palindrome[i];
                palindrome[i] = 'a';
                erase(x), mp['a']++;
                
                if(mp.size() == 1) { 
                    palindrome[i] = x;
                    erase('a'), mp[x]++;
                    continue;
                }
                
                f = true;
                break;
            }
        }
        
        if(not f) palindrome[n - 1] = 'b';
        
        return palindrome;
    }
};
