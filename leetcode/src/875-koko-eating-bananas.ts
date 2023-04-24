function minEatingSpeed(piles: number[], h: number): number {
    let start = 0;
    let end = Math.max(...piles);

    while (start <= end) {
        const mid = Math.floor((start + end) / 2);
        const time = piles.reduce((time, pile) => time + Math.ceil(pile / mid), 0);

        if (time > h) start = mid + 1;
        else end = mid - 1;
    }

    return start;
};

console.log(minEatingSpeed([3, 6, 7, 11], 8));
console.log(minEatingSpeed([30,11,23,4,20], 5));
console.log(minEatingSpeed([30,11,23,4,20], 6));
console.log(minEatingSpeed([312884470], 312884469));
console.log(minEatingSpeed(
    [332484035,524908576,855865114,632922376,222257295,690155293,112677673,
        679580077,337406589,290818316,877337160,901728858,679284947,688210097,
        692137887,718203285,629455728,941802184], 823855818));
