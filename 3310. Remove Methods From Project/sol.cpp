class Solution {
public:
    vector<int> remainingMethods(
        int n,
        int k,
        vector<vector<int>>& invocations
    ) {
        vector<vector<int>> graph(n);

        for (const auto& invocation : invocations) {
            int caller = invocation[0];
            int called = invocation[1];
            graph[caller].push_back(called);
        }

        vector<bool> suspicious(n, false);
        queue<int> q;

        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int next : graph[current]) {
                if (!suspicious[next]) {
                    suspicious[next] = true;
                    q.push(next);
                }
            }
        }

        // Any edge from outside the suspicious group into the group
        // prevents the entire group from being removed.
        for (const auto& invocation : invocations) {
            int caller = invocation[0];
            int called = invocation[1];

            if (!suspicious[caller] && suspicious[called]) {
                vector<int> allMethods(n);
                iota(allMethods.begin(), allMethods.end(), 0);
                return allMethods;
            }
        }

        vector<int> remaining;

        for (int method = 0; method < n; ++method) {
            if (!suspicious[method]) {
                remaining.push_back(method);
            }
        }

        return remaining;
    }
};
