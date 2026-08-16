//intuitive O(n**2)

class MyCalendar {
    vector<pair<int, int>> slots;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &x : slots) {
            if(x.first < end and start < x.second)
                return false;
        }
        
        slots.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
 
 //O(nlogn)
 class MyCalendar {
    set<pair<int, int>> intervals;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = intervals.lower_bound({start, end});
        
        if((next != intervals.end() and end > next->first) or (next != intervals.begin() and start < (--next)->second))
            return false;
        
        intervals.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
