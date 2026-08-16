class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_set<int> st;
        
        for(int x : arr)
            freq[x]++;
        
        for(auto &x : freq)
            st.insert(x.second);
        
        return st.size() == freq.size();
    }
};
