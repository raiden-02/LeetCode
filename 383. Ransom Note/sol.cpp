class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magMp;
        
        for(char x : magazine)
            magMp[x]++;
        
        for(char  x : ransomNote) {
            if(magMp[x] == 0)
                return false;
            magMp[x]--;
        }
        
        return true;
    }
};
