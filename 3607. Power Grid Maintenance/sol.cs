public class Solution {
    private List<SortedSet<int>> comps;
    private List<List<int>> graph;
    private List<bool> vis;
    private List<int> map;

    private void bfs(int node) {
        SortedSet<int> set = new SortedSet<int>();
        Queue<int> q = new Queue<int>();
        
        set.Add(node);
        q.Enqueue(node);
        vis[node] = true;

        while(q.Count> 0) {
            int cur = q.Dequeue();

            foreach(int neigh in graph[cur]) {
                if(vis[neigh]) continue;

                set.Add(neigh);
                q.Enqueue(neigh);
                vis[neigh] = true;
            }
        }

        comps.Add(set);
        int compIndex = comps.Count - 1;

        foreach (int compNode in set) {
            map[compNode] = compIndex;
        }
    }

    public int[] ProcessQueries(int c, int[][] connections, int[][] queries) {
        comps = new List<SortedSet<int>>();
        graph = new List<List<int>>();
        for (int i = 0; i <= c; i++) {
            graph.Add(new List<int>());
        }

        vis = Enumerable.Repeat(false, c + 1).ToList();
        map = Enumerable.Repeat(-1, c + 1).ToList();

        List<int> ans = new List<int>();

        foreach(int[] conn in connections) {
            graph[conn[0]].Add(conn[1]);
            graph[conn[1]].Add(conn[0]);
        }

        for(int i = 1; i <= c; i++) {
            if(vis[i]) continue;
            bfs(i);
        }

        foreach(int[] query in queries) {
            int q = query[0], x = query[1];

            if(q == 1) {
                if(comps[map[x]].Contains(x)) ans.Add(x);
                else {
                    if(comps[map[x]].Count > 0)
                        ans.Add(comps[map[x]].Min);
                    else
                        ans.Add(-1);
                }
            }

            else if(q == 2) {
                comps[map[x]].Remove(x);
            }
        }

        return ans.ToArray();
    }
}
