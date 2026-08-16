class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length(), ans = INT_MAX, end = 0, start = 0, minStart = 0;
        unordered_map<char, int> mp; //stores freq of t
        
        for(char x : t) mp[x]++;
        
        while(end < n) {
            if(mp[s[end]] > 0) // implies it is in t
                m--; //selecting this character in our string
            mp[s[end]]--; //decrease the frequency of all selected characters in our current string, if the char is not in t(i.e is s), it will become negative since we did not add their frequency so the default is 0
            end++;
            
            while(m == 0) { //implies we now have all the required chars of t in our cur string
                if(end - start < ans) { //updating start of the best string and minimum length
                    minStart = start;
                    ans = end - start;
                }
                mp[s[start]]++; //again deselecting/removing the char from our cur string, if char is in t it would be greater than 0, else those will go from negative to zero
                if(mp[s[start]] > 0) //inficating the char is in t, chars in s will never exceed 0
                    m++; //increasing the length of chars to be selected
                start++;
            }
        }
        
        return ans == INT_MAX ? "" : s.substr(minStart, ans);
    }
};
