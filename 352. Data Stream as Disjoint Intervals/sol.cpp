class SummaryRanges {
    set<int> st;
    vector<vector<int>> ans;

public:
    SummaryRanges() {}

    void addNum(int value) {
        st.insert(value);
    }

    vector<vector<int>> getIntervals() {
        ans.clear();

        int start = *st.begin(), end = *st.begin();

        for (auto it = next(st.begin()); it != st.end(); it++) {
            if (*it == end + 1)
                end = *it;
            else {
                ans.push_back({start, end});
                start = end = *it;
            }
        }

        ans.push_back({start, end});
        return ans;
    }
};
