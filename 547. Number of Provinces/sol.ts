function findCircleNum(g: number[][]): number {
    const n: number = g.length;
    let ans: number = 0;
    let vis: boolean[] = new Array(n).fill(false);

    const dfs = (node: number) => {
        for(let i = 0; i < n; i++) {
            if(vis[i] || g[node][i] == 0) continue;
            vis[i] = true;
            dfs(i);
        }
    }

    for(let i = 0; i < n; i++) {
        if(vis[i]) continue;

        ans += 1;
        vis[i] = true;
        dfs(i);
    }

    return ans;
};
