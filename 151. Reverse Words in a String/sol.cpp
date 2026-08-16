class Solution {
public:
    string reverseWords(string s) {
        deque<string> arr;
        stringstream ss(s);
        string k, ans;
        
        while(ss >> k)
            arr.push_front(k);
        
        while(not arr.empty())
            ans += arr.front() + " ", arr.pop_front();
        
        ans.pop_back();
        return ans;
    }
};
