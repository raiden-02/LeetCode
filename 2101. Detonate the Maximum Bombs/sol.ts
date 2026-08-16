function maximumDetonation(bombs: number[][]): number {
    const m: number = bombs.length;
    let g = new Map<number, number[]>();
    for(let i = 0; i < bombs.length; i++) {
        g.set(i, []);
    }

    for(let i = 0; i < m; i++) {
        for(let j = 0; j < m; j++) {
            if(i == j) continue;

            const xi: number = bombs[i][0];
            const yi: number = bombs[i][1];
            const ri: number = bombs[i][2];

            const xj: number = bombs[j][0];
            const yj: number = bombs[j][1];

            if((xi - xj) ** 2 + (yi - yj) ** 2 <= ri ** 2) {
                g.get(i)?.push(j);
            }
        }
    }

    let ans: number = 0;

    for(let i = 0; i < bombs.length; i++) {
        ans = Math.max(ans, bfs(m, g, i));
    }

    return ans;
};

// --- alternate solution ---

function bfs(m: number, g: Map<number, number[]>, ind: number): number {
    let vis: boolean[] = new Array(m).fill(false);
    let cnt: number = 0;
    let queue: number[] = [ind];
    vis[ind] = true;
    
    while(queue.length != 0) {
        let cur: number = queue.shift();

        for(let neigh of g.get(cur)) {
            if(vis[neigh]) continue;

            queue.push(neigh);
            vis[neigh] = true;
        }

        cnt++;
    }

    return cnt;
};
