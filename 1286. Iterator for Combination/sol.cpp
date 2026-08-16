class CombinationIterator {
    vector<string> combs;
    int ind;
public:
    CombinationIterator(string characters, int combinationLength) {
        string tmp;
        ind = 0;
        helper(characters, 0, combinationLength, tmp);
    }
    
    void helper(string const& s, int ind, int const& len, string &tmp) {
        if(tmp.length() > len) return;
        
        if(tmp.length() == len) {
            combs.push_back(tmp);
            return;
        }
        
        if(ind >= s.length()) return;
        
        tmp.push_back(s[ind]);
        helper(s, ind + 1, len, tmp);
        tmp.pop_back();
        
        helper(s, ind + 1, len, tmp);
    }
    
    string next() {
        return combs[ind++];
    }
    
    bool hasNext() {
        return ind < combs.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
