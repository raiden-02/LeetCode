class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        array<int, 3> arr{a, b, c};
        sort(arr.begin(), arr.end());

        int maxMoves = arr[2] - arr[0] - 2;
        int x = arr[1] - arr[0] - 1;
        int y = arr[2] - arr[1] - 1;
        int minMoves = 0;

        if(x == 0 && y == 0) minMoves = 0;
        else if(x == 0 || y == 0) minMoves = 1;
        else if(min(x, y) == 1) minMoves = 1;
        else minMoves = 2;

        return {minMoves, maxMoves};
    }
};
