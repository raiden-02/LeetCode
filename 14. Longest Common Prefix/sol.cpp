class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto comp = [&](string &a, string &b) {
            return a.length() < b.length();
        };
        string s = *min_element(strs.begin(), strs.end(), comp);
        
        int c = 0;
        
        while(s != "") {
            c = 0;
            
            for(string &x : strs) {
                if(x.rfind(s, 0) == 0)
                    c++;
                else
                    break;
            }
            
            if(c == strs.size())
                return s;
            else
                s.pop_back();
        }
        
        return "";
    }
};
