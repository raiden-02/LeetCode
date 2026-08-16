class Solution:
    def dfs(self, cur, g, vis, dest):
        if(cur == dest):
            return True

        for neigh in g[cur]:
            if(not vis[neigh]):
                vis[neigh] = True
                if(self.dfs(neigh, g, vis, dest)):
                    return True
        
        return False

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        g = [[] for i in range(n)]
        vis = [False for i in range(n)]

        for edge in edges:
            g[edge[0]].append(edge[1])
            g[edge[1]].append(edge[0])

        vis[source] = True
        return self.dfs(source, g, vis, destination)
