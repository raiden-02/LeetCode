class Solution {
public:
    bool isPossible(vector<int>& target) {
    //video reference - https://www.youtube.com/watch v=wTwKzSOthEM&ab_channel=HappyCoding
        if(target.size()== 1)
            return target[0] == 1;
        
        long s = 0;
        for(int &x : target)
            s += x;
        
        priority_queue<int> pq(target.begin(), target.end());
        
        while(not pq.empty() and pq.top() > 1) {
            int maxElem = pq.top(); pq.pop();
            int remain = s - maxElem;
            
            if(remain == 1) return true;
            
            int prev = maxElem % remain;
            
            if(prev < 1 or prev == maxElem)
                return false;
            
            pq.push(prev);
            s = s - maxElem + prev;
        }
        
        return true;
    }
};

// --- alternate solution ---

class Solution {
public:
    bool isPossible(vector<int>& target) {
        //video reference - https://www.youtube.com/watch v=wTwKzSOthEM&ab_channel=HappyCoding
        
        long s = 0;
        for(int &x : target)
            s += x;
        
        priority_queue<int> pq(target.begin(), target.end());
        
        while(not pq.empty() and pq.top() > 1) {
            int maxElem = pq.top(); pq.pop();
            int remain = s - maxElem;
            
            if(remain == 1) return true;
            
            if(remain == 0) remain += maxElem;
            
            int prev = maxElem % remain;
            
            if(prev < 1 or prev == maxElem)
                return false;
            
            pq.push(prev);
            s = s - maxElem + prev;
        }
        
        return true;
    }
};

// --- alternate solution ---

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long s = 0;
        for(int &x : target)
            s += x;
        
        priority_queue<int> pq(target.begin(), target.end());
        
        while(true) {
            int cur = pq.top(); pq.pop();
            
            s -= cur;
            
            if(cur == 1 or s == 1)
                return true;
            
            if(cur < s or s == 0 or cur % s == 0)
                return false;
            
            cur %= s; //prevents the tle, accelerates the subtraction the process if the max element is significantly larger than the sum of the rest
            s += cur; //add the subtracted back to the list, i,e replace it
            pq.push(cur);
        }
        
        return false;
    }
};
