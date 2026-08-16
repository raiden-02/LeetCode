class Solution {
public:
    string makeGood(string s) {
        string st;
        
        for(char x : s) {
            if(not st.empty() and ((islower(st.back()) and isupper(x)) or (isupper(st.back()) and islower(x))) and tolower(st.back()) == tolower(x))
                st.pop_back();
            else
                st.push_back(x);
        }
        
        return st;
    }
};
