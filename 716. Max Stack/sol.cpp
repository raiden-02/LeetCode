class MaxStack {
    list<int> st;
    map<int, vector<list<int>::iterator>> mp;

    void map_pop(int val) {
        mp[val].pop_back();
        if(mp[val].empty())
            mp.erase(val);
    }
public:
    MaxStack() {

    }
    
    void push(int x) {
        st.push_front(x);
        mp[x].push_back(st.begin());
    }
    
    int pop() {
        int val = st.front();
        st.pop_front();
        map_pop(val);
        return val;
    }
    
    int top() {
        return st.front();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        auto it = mp.rbegin()->second.back();
        int val = mp.rbegin()->first;
        map_pop(val);
        st.erase(it);
        return val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
