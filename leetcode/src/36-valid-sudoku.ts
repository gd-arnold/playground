function isValidSudoku(board: string[][]): boolean {
    const rows = new Map<number, Set<string>>();
    const cols = new Map<number, Set<string>>();
    const grid = new Map<string, Set<string>>();

    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            const element = board[i][j];

            if (element === ".") continue;

            const subgrid = `${Math.floor(i / 3)}${Math.floor(j / 3)}`;

            if (!rows.has(i)) rows.set(i, new Set());
            if (!cols.has(j)) cols.set(j, new Set());
            if (!grid.has(subgrid)) grid.set(subgrid, new Set());

            if (rows.get(i)!.has(element)) return false;
            if (cols.get(j)!.has(element)) return false;
            if (grid.get(subgrid)!.has(element)) return false;

            rows.get(i)!.add(element);
            cols.get(j)!.add(element);
            grid.get(subgrid)!.add(element);
        }
    }
    return true;
};

console.log(isValidSudoku(
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
));
