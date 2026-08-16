class MyCalendarThree {
    map<int, int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int count = 0, k = 0;
        mp[start]++, mp[end]--;
        
        for(auto &x : mp) {
            k = max(k, count += x.second);
        }
        
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
