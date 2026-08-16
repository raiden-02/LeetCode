function countNegatives(grid: number[][]): number {
    let ans: number = 0;
    
    for(let i = grid.length - 1; i >= 0; i--) {
        if(grid[i][grid[i].length - 1] >= 0) break;

        for(let j = grid[i].length - 1; j >= 0; j--) {
            if(grid[i][j] < 0) ans++;
            else break;
        }
    }

    return ans;
}
