class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> st;
        int i = 0, j = 0, ans = 0;
        
        while(i < word.length()) {
            if(isdigit(word[i])) {
                j = i;
                string s;
                bool f = false;
                
                while(j < word.length() && isdigit(word[j])) {
                    if(!f && word[j] != '0') {
                        i = j;
                        f = true;
                    }
                    //cout << f << " " << word[j] << endl;
                    if(f)
                        s += word[j];
                    
                    j += 1;
                }
                //cout << i << " " << j << " " << j - i << " " << word.substr(i, j - i) << endl;
                st.insert(word.substr(i, j - i));
                
                i = j;
            }
            
            else
                i += 1;            
        }
        
        return st.size();
    }
};
