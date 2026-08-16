class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mp = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> uniqueConcats;
        
        for(string &word : words) {
            string s;
            
            for(char x : word)
                s += mp[x - 'a'];
            
            uniqueConcats.insert(s);
        }
        
        return uniqueConcats.size();
    }
};
