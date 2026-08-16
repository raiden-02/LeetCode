/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> list;
    int ind = 0;

    void insert(vector<NestedInteger> &nestedList) {
        for(auto &x : nestedList) {
            if(x.isInteger()) {
                list.push_back(x.getInteger());
                continue;
            }

            insert(x.getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        insert(nestedList);
    }
    
    int next() {
        return hasNext() ? list[ind++] : -1;
    }
    
    bool hasNext() {
        return ind < list.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */



//c++
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// --- alternate solution ---

class NestedIterator {
private:
    vector<int> ans;
    int n, i;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
        n = ans.size();
        i = -1;
    }
    
    void helper(vector<NestedInteger> &nestedList) {
        for(auto &i : nestedList) {
            if(i.isInteger())
                ans.push_back(i.getInteger());
            else
                helper(i.getList());
        }
    }
    
    int next() {
        return ans[++i];
    }
    
    bool hasNext() {
        return i + 1 < n;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
