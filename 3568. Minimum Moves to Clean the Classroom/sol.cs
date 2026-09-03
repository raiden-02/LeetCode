public class Solution {
    public int MinMoves(string[] classroom, int energy) {
        int m = classroom.Length;
        int n = classroom[0].Length;

        int si = -1, sj = -1;
        int litterCount = 0;
        int[,] litterId = new int[m, n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                litterId[i, j] = -1;

                if (classroom[i][j] == 'S') {
                    si = i;
                    sj = j;
                }

                else if (classroom[i][j] == 'L') {
                    litterId[i, j] = litterCount++;
                }
            }
        }

        // no of 1s in the binary representation = litterCount
        int allCleaned = (1 << litterCount) - 1;

        var queue = new Queue<(int X, int Y, int Energy, int CollectedMask)>();
        var visited = new HashSet<(int X, int Y, int Energy, int CollectedMask)>();

        queue.Enqueue((si, sj, energy, 0));
        visited.Add((si, sj, energy, 0));

        (int X, int Y)[] directions =
        {
            (-1, 0),
            (0, -1),
            (1, 0),
            (0, 1)
        };

        int moves = 0;

        while (queue.Count > 0) {
            int size = queue.Count;

            while (size-- > 0) {
                var cur = queue.Dequeue();

                if (cur.CollectedMask == allCleaned) {
                    return moves;
                }

                if (cur.Energy == 0) {
                    continue;
                }

                foreach (var direction in directions) {
                    int ni = cur.X + direction.X;
                    int nj = cur.Y + direction.Y;

                    if (ni < 0 || ni >= m ||
                        nj < 0 || nj >= n ||
                        classroom[ni][nj] == 'X') {
                        continue;
                    }

                    int nextEnergy = cur.Energy - 1;
                    int nextMask = cur.CollectedMask;

                    if (classroom[ni][nj] == 'R') {
                        nextEnergy = energy;
                    }

                    if (classroom[ni][nj] == 'L') {
                        int id = litterId[ni, nj];
                        // set litterId bit (mark it as collected)
                        nextMask |= 1 << id;
                    }

                    var nextState = (ni, nj, nextEnergy, nextMask);

                    if (visited.Add(nextState)) {
                        queue.Enqueue(nextState);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
}
