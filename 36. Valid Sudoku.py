class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row, col, box = defaultdict(list), defaultdict(list), defaultdict(list)
        bi = -1
        
        for i in range(9):
            for j in range(9):
                cur = board[i][j]
                if cur == '.':
                    continue
                    
                if i >= 0 and i < 3:
                    if j >= 0 and j < 3:
                        bi = 1
                    if j >= 3 and j < 6:
                        bi = 2
                    if j >= 6 and j < 9:
                        bi = 3
                        
                elif i >= 3 and  i < 6:
                    if j >= 0 and j < 3:
                        bi = 4
                    if j >= 3 and j < 6:
                        bi = 5
                    if j >= 6 and j < 9:
                        bi = 6
                
                else:
                    if j >= 0 and j < 3:
                        bi = 7
                    if j >= 3 and j < 6:
                        bi = 8
                    if j >= 6 and j < 9:
                        bi = 9
                
                if cur in row[i] or cur in col[j] or cur in box[bi]:
                    return False
                
                row[i].append(cur)
                col[j].append(cur)
                box[bi].append(cur)
        
        return True
