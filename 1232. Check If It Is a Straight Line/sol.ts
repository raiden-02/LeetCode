function checkStraightLine(coordinates: number[][]): boolean {
    const n: number = coordinates.length;

    if(n <= 2) return true;

    coordinates.sort();

    const slope: number = (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);

    for(let i = 2; i < n; i++) {
        let curslope: number =  (coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]);

        if(curslope != slope) return false;
    }

    return true;
};
