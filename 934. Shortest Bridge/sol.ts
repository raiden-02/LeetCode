function shortestBridge(grid: number[][]): number {
    const dirs: number[][] = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    const k1: number[][] = [];
    const m = grid.length, n = grid[0].length;
    const vis: boolean[][] = [];

    for(let i = 0; i < m; i++) {
        vis[i] = [];
        for(let j = 0; j < n; j++) {
            vis[i][j] = false;
        }
    }

    function dfs(i: number, j: number): void {
        if(vis[i][j]) return;

        k1.push([i, j]);
        
        vis[i][j] = true;
        //console.log([i, j]);

        for(const dir of dirs) {
            let dx = i + dir[0], dy = j + dir[1];

            if(dx >= 0 && dx < m && dy >= 0 && dy < n && !vis[dx][dy] && grid[dx][dy]) {
                dfs(dx, dy);
            }
        }
    }

    function bfs(): number {
        const q: number[][] = [];
        let lvl: number = 0;

        for(const x of k1) {
            q.push(x);
        }

        while(q.length) {
            let s: number = q.length;

            while(s--) {
                let cur: number[] = q.shift()!;
                let x: number = cur[0], y: number = cur[1];

                for(const dir of dirs) {
                    let dx: number = x + dir[0], dy: number = y + dir[1];

                    if(dx >= 0 && dx < m && dy >= 0 && dy < n && !vis[dx][dy]) {
                        if(grid[dx][dy]) return lvl;
                        q.push([dx, dy]);
                        vis[dx][dy] = true;
                    }
                }
            }

            lvl++;
        }

        return lvl;
    }

    function helper(): number[] {
        for(let i = 0; i < m; i++) {
            for(let j = 0; j < n; j++) {
                if(grid[i][j]) {
                    return [i, j];
                }
            }
        }

        return [-1, -1];
    }

    const start: number[] = helper();
    dfs(start[0], start[1]);

    return bfs();
};
