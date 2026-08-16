class BrowserHistory {
    vector<string> q;
    int ind;
public:
    BrowserHistory(string homepage) {
        q.push_back(homepage);
        ind = 0;
    }
    
    void visit(string url) {
        q.erase(q.begin() + ind + 1, q.end());
        q.push_back(url);
        ind = q.size() - 1;
    }
    
    string back(int steps) {
        ind = max(0, ind - steps);
        return q[ind];
    }
    
    string forward(int steps) {
        ind = min((int)q.size() - 1, ind + steps);
        return q[ind];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
