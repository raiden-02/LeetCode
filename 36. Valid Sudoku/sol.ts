function isValidSudoku(board: string[][]): boolean {
    const row_map: Set<string>[] = Array.from({ length: 9 }, () => new Set<string>());
    const col_map: Set<string>[] = Array.from({ length: 9 }, () => new Set<string>());
    const nonant_map: Set<string>[] = Array.from({ length: 9 }, () => new Set<string>());

    function get_nonant(row: number, col: number): number {
        return Math.floor(row / 3) * 3 + Math.floor(col / 3);
    }

    for(let i = 0; i < board.length; i++) {
        for(let j = 0; j < board[0].length; j++) {
            const x = board[i][j];
            if(x == ".") continue;

            if(row_map[i].has(x)) return false;
            if(col_map[j].has(x)) return false;
            
            const nonant = get_nonant(i, j);

            if(nonant_map[nonant].has(x)) return false;
            
            row_map[i].add(x);
            col_map[j].add(x);
            nonant_map[nonant].add(x);
        }
    }

    return true;
};
