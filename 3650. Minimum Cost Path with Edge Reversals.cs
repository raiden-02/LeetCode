public class Solution {
    private const int INF = 1001;

    private int DijkstraMinCost(Dictionary<int, int>[] g, int start, int target) {
        int n = g.Length;
        int[] dist = new int[n];
        bool[] visited = new bool[n];

        Array.Fill(dist, int.MaxValue);
        dist[start] = 0;

        var pq = new PriorityQueue<int, int>();
        pq.Enqueue(start, 0);

        while (pq.Count > 0)
        {
            int u = pq.Dequeue();
            if (visited[u]) continue;
            visited[u] = true;

            if (u == target) return dist[u];

            foreach (var kv in g[u]) 
            {
                int v = kv.Key;
                int w = kv.Value;

                int nd = dist[u] + w;
                if (nd < dist[v])
                {
                    dist[v] = nd;
                    pq.Enqueue(v, nd);
                }
            }
        }

        return -1;
    }


    public int MinCost(int n, int[][] edges) {
        var g = new Dictionary<int, int>[n];
        for (int i = 0; i < n; i++)
            g[i] = new Dictionary<int, int>();

        foreach (var e in edges) {
            int a = e[0], b = e[1], w = e[2];

            if (!g[a].TryGetValue(b, out int cur) || w < cur)
                g[a][b] = w;

            int w2 = 2 * w;
            if (!g[b].TryGetValue(a, out cur) || w2 < cur)
                g[b][a] = w2;
        }

        return DijkstraMinCost(g, 0, n - 1);
    }
}
