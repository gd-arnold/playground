// Time: O(n^2)
// Space: O(n)
function threeSum(nums: number[]): number[][] {
    const result = new Map<string, number[]>();
    const elToIndxMap = new Map();

    // O(nlogn)
    nums.sort();

    // O(n)
    for (let i = 0; i < nums.length; i++) {
        elToIndxMap.set(nums[i], i);
    }

    // O(n^2)
    for (let i = 0; i < nums.length - 1; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            let third = -nums[i] - nums[j];

            // (n)
            if (elToIndxMap.has(third) && elToIndxMap.get(third) > j) {
                let first = nums[i];
                let second = nums[j];

                if (first > second) [first, second] = [second, first];
                if (first > third) [first, third] = [third, first];
                if (second > third) [second, third] = [third, second];

                const seq = `${first}${second}${third}`;
                if (!result.has(seq)) result.set(seq, [first, second, third]);
            }
        }
    }

    return [...result.values()];
};

console.log(threeSum([-1,0,1,2,-1,-4]));
