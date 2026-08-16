function numOfMinutes(n: number, headID: number, manager: number[], informTime: number[]): number {
    const helper = (id: number) => {
        if(manager[id] != -1) {
            informTime[id] += helper(manager[id]);
            manager[id] = -1;
        }

        return informTime[id];
    }

    manager.forEach((_, index) => helper(index));

    return Math.max(...informTime);
};
