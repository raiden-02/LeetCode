class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool isPresent[26] = {false};
        
        for(char x : sentence)
            isPresent[x - 'a'] = true;
        
        for(int i = 0; i < 26; i++)
            if(not isPresent[i]) return false;
        
        return true;
    }
};
