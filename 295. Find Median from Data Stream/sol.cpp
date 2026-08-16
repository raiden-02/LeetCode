//multiset intuitive n + nlogn

class MedianFinder {
    multiset<double> st;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        st.insert(num);
    }
    
    double findMedian() {
        int n = st.size();
        
        auto it = st.begin();
        advance(it, n / 2);
        
        if(n % 2)
            return *it;
        
        auto it2 = it;
        it--;
        
        return (*it + *it2) / 2;
    }
};

//O(nlogn) heap
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 class MedianFinder {
private:
    priority_queue<double> maxh;
    priority_queue<double, vector<double>, greater<double>> minh;
    int n;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top()), maxh.pop();
        
        if(maxh.size() < minh.size())
            maxh.push(minh.top()), minh.pop();
        
        n++;
    }
    
    double findMedian() {
        return n % 2 ? maxh.top() : (maxh.top() + minh.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
